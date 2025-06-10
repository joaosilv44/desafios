#include <iostream>
using namespace std;

int main() {
    int tab[3][3];
    int linha, coluna, jogador = 1, jogadas =  0;
    char vazio;
    bool vitoria=false;
    
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tab[i][j] = 0;
        }
    }
    while(!vitoria && jogadas < 9){
    cout << "\n---Tabuleiro---\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tab[i][j] == 1) vazio = 'X';
            else if(tab[i][j] == 2) vazio = 'O';
            else vazio = ' ';
            cout << " " << vazio;
            if(j < 2) cout << " |";
        }
        cout << endl;
        if(i < 2) cout << "-----------" << endl;
    }
    cout << endl;
    
    cout << "Jogador " << jogador << " (" << (jogador == 1 ? 'X' : 'O') << "), digite a linha e a coluna de 1-3: ";
    cin >> linha >> coluna;
    linha--;
    coluna--;
    
    if(linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tab[linha][coluna] == 0){
        tab[linha][coluna] = jogador;
        jogadas++;
    }else {
        cout << "Jogada inválida\n";
        continue;
    }
    
    for(int i = 0; i < 3; i++){
        if(tab[i][0] == jogador && tab[i][1] == jogador && tab[i][2] == jogador){
            vitoria = true;
            break;
            }
        if(tab[0][i] == jogador && tab[1][i] == jogador && tab[2][i] == jogador){
             vitoria = true;
             break;
            }
        }

        if(tab[0][0] == jogador && tab[1][1] == jogador && tab[2][2] == jogador){
            vitoria = true;
            break;
            }
        if(tab[0][2] == jogador && tab[1][1] == jogador && tab[2][0] == jogador){
            vitoria = true;
            break;
            }
    
        if(vitoria){
            cout << "Vitória!!";
            }else if(jogadas == 9){
                cout << "Deu velha";
            }else {
                jogador  = (jogador == 1) ? 2 : 1;
        }
    }
     cout << "\nTabuleiro final:\n";
     for(int i = 0; i < 3; i++){
         for(int j = 0; j < 3; j++){
            if(tab[i][j] == 1) vazio = 'X';
            else if(tab[i][j] == 2) vazio = 'O';
            else vazio = ' ';
            cout << " " << vazio;
            if(j < 2) cout << " |";
            }
            cout << endl;
            if(i < 2) cout << "-----------" << endl;
        }
        if(vitoria){
            cout << "Parabéns jogador " << jogador << " (" << (jogador  == 1 ? 'X' : 'O') << ") venceu!\n";
        }else {
            cout << "\nO jogo terminou empate (Deu velha!)\n";
        }
        
    return 0;
}