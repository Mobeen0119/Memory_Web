#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Edge{
public:
    string from;   //source
    string connection;  //edges
    string to;    //destination
    float effectivity; //weight

    Edge(string f,string c,string t,float e){
        from=f;
        connection=c;
        to=t;
        effectivity=e;  }
};

vector<string>memory;

void add_memories(){
    memory = {
            "Back when i broke my Cycle", "Regretting of not questioning when it matters", "Remember When we lost and important cricket match", "When we lost our joy ","Getiing hurt back when i was kid",//0-4--Pain
            "Remember when u got ur first Cycle", "When we play cricket till sunset","Remember when we won an important cricket match","Remember when u got interaction with that person","When u got new cricket bat",//4-9--Happiness
            "When someone got separated", "When we got a family trauma for a lifetime", "When we lost somewhere in a market", "When u being neglected as a child","When u experiencing spiritual or religious abuse", //9-14--Trauma
            "What is ur goal?Why u started?", "When will u found ur purpose", "When will u build something on ur own or invent something", "When will u get what u want?","When someone will benifitted from u",   //14-19--Future
            "Why we even existed?","Why we're just following","End?🤔Now What?","Why we stop inventing","What will be the End"  //19-23---Incomplete Questions

    };
}void create_graph(vector<list<Edge>>& graph) {
    add_memories();

    // 0->Pain, 1-> Happiness,2-> Trauma, 3-> Future, 4->Incomplete
    graph[0].push_back(Edge("Cycle", "Pain", memory[0], 3.8));
    graph[0].push_back(Edge("Cricket", "Pain", memory[2], 3.2));
    graph[0].push_back(Edge("Childhood", "Pain", memory[3], 2.4));
    graph[0].push_back(Edge("Childhood", "Pain", memory[4], 3.8));
    graph[0].push_back(Edge("Childhood", "Pain", memory[1], 2.1));

    graph[1].push_back(Edge("Cycle", "Happiness", memory[5], 3.0));
    graph[1].push_back(Edge("Childhood", "Happiness", memory[6], 4.0));
    graph[1].push_back(Edge("Cricket", "Happiness", memory[7], 3.5));
    graph[1].push_back(Edge("Self", "Happiness", memory[8], 4.5));
    graph[1].push_back(Edge("Cricket", "Happiness", memory[9], 3.5));

    graph[2].push_back(Edge("Self", "Trauma", memory[10], 4.0));
    graph[2].push_back(Edge("Childhood", "Trauma", memory[11], 3.4));
    graph[2].push_back(Edge("Childhood", "Trauma", memory[12], 3.6));
    graph[2].push_back(Edge("Childhood", "Trauma", memory[13], 2.5));
    graph[2].push_back(Edge("Religion", "Trauma", memory[14], 4.2));


    graph[3].push_back(Edge("Self", "Future", memory[15], 4.0));
    graph[3].push_back(Edge("Self", "Future", memory[16], 2.4));
    graph[3].push_back(Edge("Self", "Future", memory[17], 1.4));
    graph[3].push_back(Edge("Self", "Future", memory[18], 2.2));
    graph[3].push_back(Edge("Public", "Future", memory[19], 3.4));

    graph[4].push_back(Edge("Religion", "Incomplete", memory[20], 4.5));
    graph[4].push_back(Edge("Self", "Incomplete", memory[21], 3.2));
    graph[4].push_back(Edge("Self", "Incomplete", memory[22], 3.9));
    graph[4].push_back(Edge("World", "Incomplete", memory[23], 3.4));
    graph[4].push_back(Edge("Self", "Incomplete", memory[24], 4.1));
}
void show_specific_memory(vector<list<Edge>>&graph,string &type){

    vector<Edge> match;
    system("cls");
    for (int i = 0; i < graph.size(); i++) {
        for (Edge &e : graph[i]) {
            if (e.connection == type) {
                match.push_back(e);
            }
        }
    }
    const int min_year=2006;
    const  int max_year=2022;
    if (match.empty()) {
        cout << "\nNo memory found of type: " << type << endl;
    } else {
        srand(time(0));
        int idx = rand() % match.size(); //random index
        int random_year=min_year +(rand() % (max_year - min_year + 1) );
        Edge &e = match[idx];

        cout << "\nSo it's from the time "<<random_year
             << " to " << e.to
             << " with " << e.effectivity << "% effectivity on brain\n"
             <<"\t\t======U can't handle more than one======\t\t \n";
    } }
    void dream_generator(vector<list<Edge>>&graph){
        srand(time(0));
    vector<string>type;  //for selecting type
    for(auto &gr:graph){
        for(auto &e:gr){
            if (!graph.empty()) {
                if (find(type.begin(), type.end(), e.connection) == type.end()) {
                    type.push_back(e.connection);
                }
            }
        }
        }
    vector<double>type2;
        for(auto &gr:graph){
            for(auto &e:gr){
                if (!graph.empty()) {
                    if (find(type2.begin(), type2.end(), e.effectivity) == type2.end()) {
                    type2.push_back(e.effectivity);
                }
            }}
        }
        vector<string>type3;
        for(auto &gr:graph){
            for(auto &e:gr){
                if (!graph.empty()) {
                    if (find(type3.begin(), type3.end(), e.to) == type3.end()) {
                        type3.push_back(e.to);
                    }
                }
            }
        }
        vector<string>type4;
        for(auto &gr:graph){
            for(auto &e:gr){
                if (!graph.empty()) {
                    if (find(type4.begin(), type4.end(), e.connection) == type4.end()) {
                        type4.push_back(e.from);
                    }
                }
            }
        }
    if(type.empty() || type2.empty() || type3.empty() || type4.empty()){
        cout<<"\nBrain is busy right now for other thing....Live without dream\n";
        return;
    }
    string random=type[rand() % type.size()];
    double random2=type2[rand() % type2.size()];
    string random3=type3[rand() % type3.size()];
    string random4=type4[rand() % type4.size()];

        int min_year=2000;
        int max_year=2030;


        int random_year = min_year + (rand() % (max_year - min_year + 1));

        cout << "\nSo u had a dream about " << random << " thoughts.\n";
        cout << "while u were in ur " << random4 << ".\n";
        cout << "and thinking " <<  random3  << ".\n";
        cout << "which effect ur brain around " << random2 << "% out of 5."<<"\n";
        cout << "and this actually happening in a year " << random_year << ".\n";

    }

void show_all_memory(vector<list<Edge>>&graph,int v);
int mem_in=0;
void add_memory(vector<list<Edge>>&graph,int v) {
    system("cls");
    string mem;
    int n, choice;
    string effect;
    create_graph(graph);
    cout << "How many memories u want to add";
    cin >> n;
    float rate;
    string keyword;
    for (int i = 1; i < n + 1; i++) {

        cout << "Enter the keyword of the memory : ";
        cin >> keyword;
        cout << "\n1.Pain\n2.Happiness  \n3.Trauma \n4.Incomplete\n5.Future\nHow it effect you : ";
        cin >> choice;
        switch (choice) {
            case 1:
                effect = "Pain";
                mem_in = 0;
                mem_in++;
                break;
            case 2:
                effect = "Happiness";
                mem_in = 5;
                mem_in++;
                break;
            case 3:
                effect = "Trauma";
                mem_in = 9;
                mem_in++;
                break;
            case 4:
                effect = "Future";
                mem_in = 14;
                mem_in++;
                break;
            case 5:
                effect = "Incomplete";
                mem_in =19;
                mem_in++;
                break;

            default:
                effect = "Unknown";
                mem_in = 24;
                mem_in++;
                break;
        }
        bool found=false;
        cout << "\nEnter how much it effect ur brain(rate out of 5): ";
        cin >> rate;
        cout<<"\nAnd what's actually the memory : ";
        cin>>mem;
        cin.ignore();
        found=false;
        for(auto &e:graph[mem_in]){
            if(e.to==keyword && e.connection==effect){
                if(e.effectivity != rate) {
                    cout<<"\nOhh! i remember  few things from that type before\n";
                    e.effectivity=rate;
                    cout<<"\nUpdated memory with new effectivity rate";}
                else cout<<"memory existed with same rate";
                found=true;
                break;
            }
        }
        if(!found){
            memory.push_back(mem);
            graph[mem_in].push_back(Edge(keyword,effect,mem,rate));
            cout<<"\nNew memory added successfully";

        }}
    cout<<"\n Now new memory structured in the catogary of "<<effect;
    cout<<"\nHere are some related memories to that \n";
    show_specific_memory(graph,effect);
}
void deleting_memory(vector<list<Edge>>&graph,int index){
    create_graph(graph);
    system("cls");
    string type=memory[index];
    if(index < 0 && index>memory.size()){
        cout<<"\nThere is no such memory i remember";
    }
    else if(memory[index].empty()){
        cout<<"\nThere is no memory index to delete\n";
    }else{
        cout<<"\nmemory  "<<type<<"is going to be deleted \n";
        memory.erase(memory.begin() + index);
        for (auto &edges : graph) {
            edges.erase(
                    remove_if(edges.begin(), edges.end(),
                              [&](const Edge &e) { return e.connection == type; }
                    ),
                    edges.end()
            );
        }
    } }
void show(vector<list<Edge>>&graph,int curr,bool vis[],int v) {
    system("cls");
    int index,choice;
    cout << curr << "  " << endl;
    vis[curr] = true;

    for (Edge &e: graph[curr]) {
        if (!vis[curr]) {
            show(graph, curr, vis,v);
        }
    }
    for(int i=0;i<1;i++){
        cout<<"\nJust want to return to the  home screen(press 0) or want to forget something(press 1) "
              " or want to add something(press 2)?";
        cin>>choice;

        if(choice==0) break;
        else if(choice==1){
            cout<<"If u want to delete Enter the index : ";
            cin>>index;
            deleting_memory(graph,index);
        }else if(choice==2){
            add_memory(graph,v);
        }
        cout<<"Invalid choice ";  break; }
}
void show_all_memory(vector<list<Edge>>&graph , int v){
    string curr;
    vector<bool>vis(v,false);
    cout<<"\nHere is the list to recalled for all memories\n";
    for(int i=0;i<graph.size();i++){
        for(Edge &e:graph[i]){
            cout<<i<<" from the "<<e.from<<" to the "<<e.to<<" and the connection is "<<e.connection<<" with the "<<e.effectivity<<"% of effectiveness on brain\n";
        }
    }}
int main(){
    int v=5;
    vector<list<Edge>>graph(v);
    create_graph(graph);
    int choice,index;
    do {
        cout << "\n\t\tWelcome to the brain....Control  ur brain if ur brain let to\t\t\n";
        cout << "\n1->Want to add some memories" << endl;
        cout << "2->Tired of it? Want to forget \n";
        cout << "3->Want to recall all ur memories?Kind of messy.....\n";
        cout << "4->Or just want to recall some specific memories\n";
        cout<< "5->Want to sleep \n";
        cout << "6->Any suggestion to ur brain(anything)\n(press 0 for to end this)\n";

        cout << "\nChoice is yours...Enter : ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_memory(graph, v);
                break;
            case 2 :
                cout << "Enter a index where  u want to delete : ";
                cin >> index;
                deleting_memory(graph, index);
                break;

            case 3:
                show_all_memory(graph, v);

            case 4: {
                int n;
                string type;
                cout
                        << "\n1.Pain\n2.Future,\n3.Trauma\n4.Happiness\n5.Incomplete Questions\n6.exit\nEnter ur specific choice which  type of memories u want to recall ";
                cin >> n;
                switch (n) {
                    case 1:
                        type = "Pain";
                        cout << "\n So u want to recall some sad memories\n";
                        break;
                    case 2 :
                        type = "Future";
                        cout << "\n\t\tSo let's take a ride to future \n";
                        break;
                    case 3:
                        type = "Trauma";
                        cout << "\n\t\tBuckle up!!!There is many ups and down \n";
                        break;
                    case 4:
                        type = "Happiness";
                        cout << "\n\t\tTime to smile a bit\n";
                    case 5:
                        type = "Incomplete";
                        cout << "\n\t\t Wants to be self obsessed\n";
                        break;
                    case 6:
                        cout << "\n\t\tSo u chose to be back to main screen\n";
                        break;
                    default:
                        cout << "\n\t\tFirst get affected by it then ask to recall\n";
                        break;
                }
                show_specific_memory(graph, type);
                break;
            }
            case 5 :{
                dream_generator(graph);
                break;
            }
            case 6 : {
                string suggestion;
                cout << "\nSuggest by staying in ur limit:";
                cin >> suggestion;
                cout << "\nWe may look to it later \n";
                break;
            }
            default:{
                        cout << "\nEnd? Now follow my command \n";
                break;
        }}
    }
    while(choice!=0);

    return 0;
}