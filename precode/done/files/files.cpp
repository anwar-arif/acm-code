#include<bits/stdc++.h>
using namespace std;

void using_stream(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "error: cannot open file " << filename << endl;
        return; 
    }

    ofstream output("output.txt");

    string line;
    while (getline(file, line)) {
        output << line << endl;
    }

    file.close();
    output.close();
}

void using_freopen(string filename) {
    freopen(filename.c_str(), "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    while (getline(cin, line)) {
        cout << line << endl;
    }
}

// Function to create sample data files for testing
void createSampleFiles(string basicFileName, string detailsFileName) {
    // Create file1.csv (name, type, weight)
    std::ofstream file1(basicFileName);
    file1 << "Name,Type,Weight\n";
    file1 << "Tyrannosaurus Rex,Theropod,7000\n";
    file1 << "Triceratops,Ceratopsid,6000\n";
    file1 << "Velociraptor,Theropod,15\n";
    file1 << "Stegosaurus,Stegosaur,5000\n";
    file1 << "Brachiosaurus,Sauropod,80000\n";
    file1 << "Allosaurus,Theropod,2300\n";
    file1 << "Parasaurolophus,Ornithopod,2500\n";
    file1.close();

    // Create file2.csv (name, leg_length, period, diet)
    std::ofstream file2(detailsFileName);
    file2 << "Name,LegLength,Period,Diet\n";
    file2 << "Tyrannosaurus Rex,3.2,Cretaceous,Carnivore\n";
    file2 << "Triceratops,1.8,Cretaceous,Herbivore\n";
    file2 << "Velociraptor,0.8,Cretaceous,Carnivore\n";
    file2 << "Stegosaurus,2.1,Jurassic,Herbivore\n";
    file2 << "Brachiosaurus,5.2,Jurassic,Herbivore\n";
    file2 << "Allosaurus,2.9,Jurassic,Carnivore\n";
    file2 << "Parasaurolophus,2.3,Cretaceous,Herbivore\n";
    file2.close();

    std::cout << "Sample files created: " << basicFileName << " and " << detailsFileName << endl;
}


int main() {
    string sample_file = "dinosaur_basic.csv";
    string details_file = "dinosaur_details.csv";
    createSampleFiles(sample_file, details_file);

    // using_stream(sample_file);
    using_freopen(sample_file);
    return 0;
}