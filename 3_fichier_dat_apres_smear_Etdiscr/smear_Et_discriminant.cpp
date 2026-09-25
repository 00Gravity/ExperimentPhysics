#include <iostream>
#include <fstream>
#include <vector>
#include <TRandom3.h>
#include <TLorentzVector.h>
#include <TMath.h>

using namespace std;

const int NUM_COLS_INITIAL = 4; 

int main() {
    ifstream fichier("p_hqq.dat");
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier de données." << endl;
        return 1;
    }

    
    vector<vector<double>> data;
    double valeur;

    
    while (fichier >> valeur) {
        vector<double> ligne(NUM_COLS_INITIAL, valeur);
        for (int i = 1; i < NUM_COLS_INITIAL; ++i) {
            fichier >> ligne[i];
        }
        data.push_back(ligne);
    }
    fichier.close();

   
    int num_lignes = data.size();
    if (num_lignes % 2 != 0) {
        cerr << "Erreur : Le nombre de lignes du fichier doit être pair." << endl;
        return 1;
    }

    
    TRandom3 rand; 
    for (int i = 0; i < num_lignes; ++i) {
        data[i][2] = data[i][2] + data[i][2] * 0.035 * rand.Gaus(0, 1); 
    }

    
    ofstream fout("r_hqq.dat");
    if (!fout) {
        cerr << "Erreur : Impossible d'ouvrir le fichier de sortie pour écriture." << endl;
        return 1;
    }

    
    for (int i = 0; i < num_lignes; i += 2) {
        
        TLorentzVector quark(data[i][0], data[i][1], data[i][2], data[i][3]);
        TLorentzVector Quark(data[i + 1][0], data[i + 1][1], data[i + 1][2], data[i + 1][3]);

        
        TLorentzVector Z_boson = quark + Quark;

        
        double Mz = Z_boson.M();

        
        double m_rec = sqrt(pow(sqrt(data[i][3]) + sqrt(data[i + 1][3]), 2) - 2 * sqrt(data[i][3]) * sqrt(data[i + 1][3]));

        
        double cos_theta_z = Z_boson.CosTheta();

        
        
    
        TVector3 boostvector = - Z_boson.BoostVector();
        quark.Boost(boostvector); 
        double cos_theta_star = quark.Vect().Dot(Z_boson.Vect()) / (Z_boson.Vect().Mag() * quark.Vect().Mag());
        

        
        fout << Mz <<" "<< m_rec <<" "<< cos_theta_z  <<" "<< cos_theta_star << endl;
    }

    fout.close();

    cout << "Les résultats ont été calculés et écrits dans le fichier resultats_energies.dat." << endl;

    return 0;
}
