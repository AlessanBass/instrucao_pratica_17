    #include <iostream>
    #include <fstream>
    #include <vector> 
    #include <string>

    using namespace std;

    class Mensagem {
        private:
            int idDeQuemEscreveu;
            string texto;

        public:
            void setIdDeQuemEscreveu(int _idDeQuemEscreveu) {
                idDeQuemEscreveu = _idDeQuemEscreveu;
            }

            void setTexto(string _texto) {
                texto = _texto;
            }

            int getIdDeQuemEscreveu() {
                return idDeQuemEscreveu;
            }

            string getTexto() {
                return texto;
            }

            void escreverMensagem(){
                ofstream escrita;
                escrita.open("mensagens.txt", ios_base::app);
                string texto;
                cout << "Conte sua historia: ";
                getline(cin, texto);

                escrita << idDeQuemEscreveu;
                escrita << " ";

                escrita << texto;
                escrita << endl;
                escrita.close();


        }

        vector<string> quebralinha(string _linha){
            vector<string> vetor;
                size_t pos = 0;
                while ((pos = _linha.find(" ")) != string::npos) {
                    string palavra = _linha.substr(0, pos);
                    vetor.push_back(palavra);
                    _linha.erase(0, pos + 1);
                }
                // A última palavra, após o último espaço em branco
                vetor.push_back(_linha);

        return vetor;
        
    }

        void listarMensagens(string _idContato){
                vector<string> dados;
                ifstream lista("mensagens.txt");
                if(lista.is_open()){
                    string linha;
                    while (getline(lista, linha))
                    {
                        //getline(lista, linha);
                        dados = quebralinha(linha);
                        if(dados[0] ==  _idContato){
                            cout << "Mensagem -> " << linha << endl;
                        }

                    }
                    lista.close();
                    
                }else{
                    cout << "Erro ao abrir" << endl;
                }

        }

        
    };

    class Contato{
        private:
        int id;
        string nome;
        string telefone;
        string email;
        string amigos;
        vector<Mensagem> msg;


        public:
        void setId(int _id){
            id = _id;
        }

        void setNome(string _nome){
            nome = _nome;
        }

        void setTelefone(string _telefone){
            telefone = _telefone;
        }

        void setEmail(string _email){
            email = _email;
        }

        void setAmigos(string _amigos){
            amigos = _amigos;
        }

        string getNome(){
            return nome;
        }

        string getTelefone(){
            return telefone;
        }

        string getEmail(){
            return email;
        }

        int getId(){
            return id;
        }

        string getAmigos(){
            return amigos;
        }


        void criarContato(){
            ofstream escrita;
            escrita.open("contatos.txt", ios_base::app);

            //Salvar o ID tbm
            escrita << id;
            escrita << " ";
            cout << "Infome o nome do contato: " << endl;
            getline(cin, nome);
            escrita << nome;
            escrita << " ";

            cout << "Infome o email do contato: " << endl;
            getline(cin, email);
            escrita << email;
            escrita << " ";

            cout << "Infome o telefone do contato: " << endl;
            getline(cin, telefone);
            escrita << telefone;
            escrita << endl;

            /* cout << "Infome os amigos separados por virgula " << endl;
            getline(cin, amigos);
            escrita << amigos;
            escrita << endl; */


            escrita.close();

        }


        void listarContatos(){
            vector<string> dados;
            ifstream lista("contatos.txt");
            if(lista.is_open()){
                string linha;
                while (getline(lista, linha))
                {
                    //getline(lista, linha);
                    dados = quebralinha(linha);
                    cout << "---------------------------" << endl;
                    cout << "Nome : " << dados[1] << endl;
                    cout << "Email : " << dados[2] << endl;
                    cout << "Telefone : " << dados[3] << endl;
                    //cout << "---------------------------" << endl;
                    //cout << "Amihos : " << dados[4] << endl;

                }
                lista.close();
                
            }else{
                cout << "Erro ao abrir" << endl;
            }

        }



    vector<string> quebralinha(string _linha){
            vector<string> vetor;
                size_t pos = 0;
                while ((pos = _linha.find(" ")) != string::npos) {
                    string palavra = _linha.substr(0, pos);
                    vetor.push_back(palavra);
                    _linha.erase(0, pos + 1);
                }
                // A última palavra, após o último espaço em branco
                vetor.push_back(_linha);

                // Agora o vetor contém as palavras que estavam na linha
            /*    for (const std::string& palavra : vetor) {
                    std::cout << palavra << std::endl;
                } */
        return vetor;
        
    
    }
    
    int carregarContatos(vector<Contato>& contatos) {
        int ultimoId = 0;  // Inicialize com 0
        ifstream lista("contatos.txt");
        if (lista.is_open()) {
            string linha;
            while (getline(lista, linha)) {
                vector<string> dados = quebralinha(linha);

                Contato novoContato;
                int id = stoi(dados[0]);  // Converte o ID para inteiro
                if (id > ultimoId) {
                    ultimoId = id;  // Atualize o último ID se encontrarmos um maior
                }
                novoContato.setId(id);
                novoContato.setNome(dados[1]);
                novoContato.setEmail(dados[2]);
                novoContato.setTelefone(dados[3]);
                //novoContato.setAmigos(dados[4]);

                contatos.push_back(novoContato);
            }
            lista.close();
        } else {
            cout << "Erro ao abrir o arquivo de contatos" << endl;
        }
        return ultimoId;
    }

    vector<int> retornaAmigos(string _amigos){
        vector<int> amigos;
        for(int i=0; i<_amigos.length(); i++){
            if(_amigos[i] != ','){
                string charAsString(1, _amigos[i]);
                int numero = stoi(charAsString);
                amigos.push_back(numero);
            }
        }

        return amigos;
    } 


    };

class Amizade {
    private: 
     int idConato;
     int idAmigo;

     public:
     void setIdContato(int _idContato){
        idConato = _idContato;
     }

     void setIdAmigo(int _idAmigo){
        idAmigo = _idAmigo;
     }

     int getIdContato(){
        return idConato;
     }

     int getIdAmigo(){
        return idAmigo;
     }



      vector<string> quebralinha(string _linha){
            vector<string> vetor;
                size_t pos = 0;
                while ((pos = _linha.find(" ")) != string::npos) {
                    string palavra = _linha.substr(0, pos);
                    vetor.push_back(palavra);
                    _linha.erase(0, pos + 1);
                }
                // A última palavra, após o último espaço em branco
                vetor.push_back(_linha);

                // Agora o vetor contém as palavras que estavam na linha
            /*    for (const std::string& palavra : vetor) {
                    std::cout << palavra << std::endl;
                } */
        return vetor;
        
    
    }

     void carregarAmizades(vector<Amizade>& a){
        ifstream lista("amizades.txt");
        string linha;
        while (getline(lista, linha)) {
            vector<string> dados = quebralinha(linha);
            Amizade amg;
            int id1 = stoi(dados[0]);
            int id2 = stoi(dados[1]);

            amg.setIdContato(id1);
            amg.setIdAmigo(id2);

            a.push_back(amg);

        }

        lista.close();
        
     }

     void criarAmizade(){
        ofstream escrita;
        escrita.open("amizades.txt", ios_base::app);

        cout << "Fazer amigo de: ";
        cin >> idConato;
        escrita << idConato;
        escrita << " ";

        cout << "Com quem ? ";
        cin >> idAmigo;
        escrita << idAmigo;
        escrita << endl;


        escrita.close();
     }
};


    int main(){
        
        vector<Contato> contatos;
        Contato c;
        Mensagem m;
        vector<Amizade> amigos;
        Amizade a;
        string teste;
        int idContato;
        idContato = c.carregarContatos(contatos);
        a.carregarAmizades(amigos);
        cout << "Tamamho de amigos: " << amigos.size() << endl;
        /*
           1° Mudar a abordagem de fazer amizades -ok
           2° Talvez mudar a persistencia das amizades - ok
           3° Verificar se uma amizade já foi criada

        */



        int op;
        do{
            cout << "-------- MENU -----" << endl;
            cout << "[1] CRIAR CONTATO" << endl;
            cout << "[2] LISTAR CONTATOS" << endl;
            cout << "[3] LISTAR CONTATOS DE ALGUEM" << endl;
            cout << "[4] CRIAR AMIZADE" << endl;
            cout << "[5] ESCREVER UMA MENSAGEM" << endl;
            cout << "[6] VER MENSAGENS DE UM CONTATO" << endl;
            cout << "[7] SAIR" << endl;
            cin >> op;
            cin.ignore();


            switch (op)
            {
            case 1:
                cout << ">>>>>> CRIACAO CONTATO <<<<" << endl;
                c.setId(idContato+1);
                c.criarContato();
                cout << "=============================" << endl;

                //OBS: Ao terminar de criar um contato carregar novamente os contatos
                
                break;

            case 2:
            cout << ">>>>>> LISTA DE CONTATOS <<<<" << endl;
                c.listarContatos();
            cout << "=============================" << endl;
            break;

            case 3:
            
            int busca;
            cout << "Buscar amigos de: "<< endl;
            cin >> busca;
            //vector<int> amigosDoContato;
            for(int i = 0; i<contatos.size(); i++){
                if(contatos[i].getId() == busca){ //achei quem tava procurando
                    for(int j = 0; j<amigos.size(); j++){ 
                            if(amigos[j].getIdContato() == busca){
                                cout << "Nome : " <<contatos[amigos[j].getIdAmigo()-1].getNome() << endl;
                            }
                    }
                }
            }


            break;

            case 4:
            cout << ">>>> CRIANDO AMIZADE <<<< " << endl;
            a.criarAmizade();
            break;

            case 5:
            int idEscritor;
            cout << "Qual contato vai escrever?" << endl;
            cin >> idEscritor;
            cin.ignore();
        
            m.setIdDeQuemEscreveu(idEscritor);
            m.escreverMensagem();
            break;

            case 6:
            //int busca;
            cout << "Buscar mensagem de qual contato? "<< endl;
            cin >> teste;
            m.listarMensagens(teste);

            break;


            case 7:
            break;

            
            default:
                cout << "Opcao invalida, tente novamente" << endl;
                break;
            }


        }while (op != 7); 
        

        return 0;
    }