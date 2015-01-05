#include <iostream>
#include <unordered_map>

using namespace std;

class Make{
public:
    string Name;
    Make(string name){
        //constructor
        Name = name;
    }
    bool operator==(const Make &that)const{
        return Name == that.Name;
    }
};

class Model{
public:
    string Name;
    int Year;
    Model(string name, int year){
        //constructor
        Name = name;
        Year = year;
    }
    bool operator==(const Model &that)const{
        return Name == that.Name && Year == that.Year;
    }
};

class ModelHash{
public:
    size_t operator()(const Model &model)const{
        return hash<string>()(model.Name) ^ hash<int>()(model.Year);
    }
};

int main(){
    unordered_map<Model, Make, ModelHash> model2make;
    Model tacoma2012("Tacoma", 2012);
    Model civic2010("Civic", 2010);
    Model tundra2013("Tundra", 2013);

    Make toyota("Toyota");
    Make honda("Honda");

    model2make.emplace(tacoma2012, toyota);
    model2make.emplace(tundra2013, toyota);
    model2make.emplace(civic2010, honda);

    //auto &it = model2make.find(tacoma2012);

    for(auto &itr: model2make){
        cout<<itr.first.Name<<" "<<itr.first.Year<<endl;
    }

//    cout<<model2make.tacoma2012<<endl;
//    table.emplace("foo", "bar");
//    cout<<table["foo"]<<endl;
    return 0;
}
