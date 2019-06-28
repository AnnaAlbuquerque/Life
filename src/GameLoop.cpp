#include "../include/GameLoop.h"

void GameLoop::initialize(int argc, char *argv[]){

    if(read_options(argc, argv) == -1 ){
        exit(EXIT_FAILURE);
    }

    read_file();

    init_msg();

    life.print_configuration();

}

int GameLoop::read_options (int argc, char *argv[]){

    //This struct represents all options that the user can enter
    struct option tempOptions[] = {
        //long_name, how_many_arguments, ,short_name
        {"imgdir", 1, 0, 'i'}, 
        {"maxgen", 1, 0, 'm'},
        {"fps", 1, 0, 'f'},
        {"blocksize", 1, 0, 'b'},
        {"bkgccolor", 1, 0, 'c'},
        {"alivecolor", 1, 0, 'a'},
        {"outfile", 1, 0, 'o'},
        {"help", no_argument, 0, 'h'},
    };

    //To the program works we need at least one argument, that's the file with initial configuration
    if (argc < 2){
        std::cerr << "\n\033[0;31mMissing argument.\033[0m\n\n";
        help_msg();
        return -1;
    }

    int userOpt; //aux variable

    //going through the arguments
    while(optind < argc){
        if((userOpt = getopt_long(argc, argv, "i:m:f:b:c:a:o:h", tempOptions , NULL)) != -1){
            //userOpt assumes current argument
            switch (userOpt){
                case 'i': //imgdir
                    options.imgdir = optarg;
                    break;
                case 'm': //maxgen
                    options.maxgen = atoi(optarg);
                    break;
                case 'f': //fps
                    options.fps = atoi(optarg);
                    break;
                case 'b': //blocksize
                    options.blocksize = atoi(optarg);
                    break;
                case 'c': //bkgcolor
                    options.bkgcolor = optarg;
                    break;
                case 'a': //alivecolor
                    options.alivecolor = optarg;
                    break;
                case 'o': //outfile
                    options.outfile = optarg;
                    break;
                case 'h': default: // help or no valid argument
                    help_msg();
                    return -1;

            }
        } else{ //after go through all the vector, this will safe inputfile path
            options.inputfile = argv[optind++]; 
        }
    }

    if(options.inputfile == ""){
        std::cerr << "\n\033[0;31mIncorrect Input File.\033[0m\n\n"; 
        help_msg();
        return -1;
    }

    return 0;
}

void GameLoop::read_file(){
    std::ifstream file;
    file.exceptions(std::ifstream::badbit);

    std::cout << ">> Trying to open input file (" << options.inputfile << ")... ";
        file.open(options.inputfile);  // Opening file in reading mode

        // Checking if the file opened successfully
        if (!file) {
                std::cerr << "\n\033[0;31m >> Error: Opening/Reading file\033[0m\n";
                exit(EXIT_FAILURE);
        }

        std::cout << "File opened successfully! \n";
        std::cout << ">> Processing data ... \n";

        int r, c; //aux to safe number of rows and columns
        char cAlive; //aux that will safe char used to alive cells
        

        file >> r >> c; //save number of rows and columns
        life.set_rows_columns(r,c);//setting GameLoop number of rows and columns

        file >> cAlive; //save char used to living cells
        set_alive_char(cAlive);

        std::cout <<"Rows: "<< life.get_rows() << "  Columns: "<< life.get_columns()<< std::endl;
        std::cout << "Char alive: "<< get_alive_char() << std::endl;

        int i = 0;
        std::string line;
        std::vector<position> vec_posi;

        while((std::getline(file,line))  && (i < life.get_rows())){
            for(int j = 0; j < (int)line.size() && (j < life.get_columns()); j++ ){
                if(line[j] == get_alive_char()){
                    position aux;
                    aux.rowIndex = i;
                    aux.columnIndex = j + 1;
                    vec_posi.push_back(aux);
                }
            }

            i++;
        }

        life.set_alive(vec_posi);
        life.set_vector_alive(vec_posi);

        file.close();

        std::cout<<"Data File sucefully read !!"<< std::endl;
}

bool GameLoop::GameOver(){
    if(extint() || stable() || options.maxgen == number_configuration){
        return true;
    }else{
        return false;
    }
}

void GameLoop::process_events(){
    //on our first iteration we just need to push back the current alive vector to log. since we don't need to apply the rules
    std::vector<position> aux_alivecell;
    
    if (number_configuration == 0){
        for (int i = 0; i < (int)life.get_alive().size(); i++){
            auto vecalive = life.get_alive();
            log[number_configuration].push_back(vecalive[i]);
        }
        
    }else{

        //Applying the rules - we will go through all the matrix an check neighbours        

        for (int i = 1; i < life.get_rows(); i++){
            for(int j = 1; j < life.get_columns(); j++){                
                if (life.check_neighbors(i,j) == 3){
                    //getting position
                    position auxpos;
                    auxpos.rowIndex = i;
                    auxpos.columnIndex = j;

                    //pushing back at aux alive vector
                    aux_alivecell.push_back(auxpos);

                }else if (life.check_if_alive(i,j)){
                    if(life.check_neighbors(i,j) <= 3 && life.check_neighbors(i,j) >= 2){
                        position auxpos;
                        auxpos.rowIndex = i;
                        auxpos.columnIndex = j;

                        //pushing back at aux alive vector
                        aux_alivecell.push_back(auxpos);
                    }
                }
            }
        }

        //By the end we will have a vector of alive cells

        //We will now reset the configuration - all the cells are going to be dead
        life.reset_config();

        //Setting the vector of alive to the new one
        life.set_vector_alive(aux_alivecell);

        //setting cell to alive on the matrix
        life.set_alive(aux_alivecell);

        number_configuration++;
        for (int i = 0; i < (int)life.get_alive().size(); i++){
            log[number_configuration].push_back(aux_alivecell[i]);
        }
        
    }
}

void GameLoop::render(){
    std::cout << "Configuration number: " << number_configuration + 1 << std::endl;
    //printing configuration
    life.print_configuration();

    std::cout << std::endl; 
}

bool GameLoop::extint(){
    if (life.get_alive().size()==0){
        std::cout<< "Configuration is extint \n";
        return true;
    }else{
        return false;
    }
}

bool GameLoop::stable(){
    int equal_count = 0;    

    //going through the vector
    for (int i = 0; i < number_configuration; i++){
        
        // used to check all configuration cells
        for(int j = 0; j < (int)log[number_configuration].size(); j++){

            //first check if size is equal
            if(log[i].size() == log[number_configuration].size()){

                //goint through all the alive positions
                if(log[i][j].rowIndex == log[number_configuration][j].rowIndex && log[i][j].columnIndex == log[number_configuration][j].columnIndex){
                    equal_count++;
                    break;
                }
            }else{
                break;
            }
        }

        if (equal_count == (int)log[number_configuration].size()){
            return true;
        }else{
            equal_count = 0;
        }
    }

    return false;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GETS

Life GameLoop::get_life(){
    return life;
}

char GameLoop::get_alive_char(){
    return alive_char;
}

int GameLoop::get_fps(){
    return options.fps;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SETS

void GameLoop::set_alive_char(char c){
    alive_char = c;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> OUTPUT
void GameLoop::help_msg(){
    std::cout<<"Life options: \n";
    std::cout<<"--help \n";
    std::cout<<"--imgdir <path> \n";
    std::cout<<"--maxgen <num> \n";
    std::cout<<"--fps <num> \n";
    std::cout<<"--blocksize <num> \n";
    std::cout<<"--bkgcolor <color> \n";
    std::cout<<"--alivecolor <color> \n";
    std::cout<<"--outfile <filename> \n";

    std::cout<<"Available colors: \n";
    std::cout<<"BLACK BLUE CRIMSON DARK_GREEN DEEP_SKY_BLUE DODGER_BLUE \n"
             <<"GREEN LIGHT_BLUE LIGHT_GREY LIGHT_YELLOW RED STEEL_BLUE \n"    
             <<"WHITE YELLOW \n";

};

void GameLoop::init_msg(){
    std::cout<< "\n";
    std::cout << "WELCOME \n";
    std::cout << "LIFE GAMING STARTING \n";
};