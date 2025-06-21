#ifndef TXTMANIPULL_HPP
#define TXTMANIPULL_HPP
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>


namespace TXTManipulation {
    class ReadFile {
        private:
            std::string path;
            std::vector<std::string> content;

        public:
            ReadFile(std::string filePath) {
                this->path = filePath;
            }

            int read() {
                std::ifstream arquivo(this->path);

                if (!arquivo.is_open()) {
                    std::cerr << "Erro ao Abrir o Arquivo" << std::endl;
                    return 1;
                }

                std::string linha;

                while (std::getline(arquivo, linha)) {
                    this->content.push_back(linha);
                }

                arquivo.close();

                return 0;
            }

            std::vector<std::string> getValue() {
                return this->content;
            }
    };

    class WriteFile {
    private:
        std::string path;
        std::vector<std::string> content;

    public:
        WriteFile(std::string path, std::vector<std::string> content) {
            this->path = path;
            this->content = content;
        }

        int write() {
            std::ofstream nFile(this->path);

            if (!nFile.is_open()) {
                std::cerr << "ERROR! File is Not Open!\n";
                return 1;
            }
            
            for (std::string c : this->content) {
                nFile << c;
            }

            nFile.close();

            return 0;
        }
    };

    std::vector<std::string> split(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;

        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        
        return tokens;
    }
}

#endif