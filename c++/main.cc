#include <iostream>
#include <string>
#include <vector>
#include <memory>


//TODO: VECS

using namespace std;

//there exists something called a unnion, but fuck em, so do enums, i don't even use constant let alone const structs
// Self referential structures, used in data structures like linked lists, gotta check out later for sure
struct GfG {
    int val;
    GfG *next;
};

int x=5;
vector<int> vec = {5,6,8,9,5,7};

int yo(int k = 20000);
string hey();

//definiction
void changepoint(int* x){
    *x = 100;
}

//there is such a thing as an online function, it makes some things fastser: it basically pushes the function code to insid ethe main func instead of calling it from far far away
inline void change(int& x){
    x=50;
}

struct structest {
    float sx, sy;
    float sum(){
        return sx + sy;
    }
};

typedef struct structest2{
    int x;
} stt;





int main() {

    //std::strings, they are treated like vectors and most vector features work on them
    string str = "wubba lubba dub dub";
    cout << str.length() << " | " << str.size() << endl;
    string substr = str.substr(0, 5);
    cout << substr << endl;

    vector<int> vec = {1,2};
    vector<int> v(vec);
    v[0];
    v.front();
    v.back();
    v.push_back(10); 
    v.pop_back();     
    v.insert(v.begin(), 20);   
    v.erase(v.begin());     
    v.clear();        
    v.resize(10);        


    int var;
    //input
    cin >> var;
    //output
    cout << var << endl;
    //error
    cerr << "error yo" <<endl;
    //if
    if(var%2 == 0){
        cout << "pair var?" << endl;
    }else{
        cout << "unique var?" << endl;
    }
    //switch
    switch (var){
        case 1:
            cout << "var is 1" << endl;
            break;
        case 5:
            cout << "var is 5" << endl;
            break;
        default:
            cout << "i don't know what kind of shinanigans you spewing" << endl;
    }
    //loops
    //for
    for(int i=0; i<10; i++){
        cout << "the i equals" << i << endl;
    }
    int xx = 2;
    //while, do while also exits
    while(xx<10){
        cout << "xx needs more" << endl;
        xx++;
    }
    //forech in c++
    for(auto x:vec){
        cout << x << " is a vec element" << endl;
    }
    cout << "yo the first loop is over now the poointer one" << endl;

    //the cooler foreach
    for (auto &x:vec){
        x=x+1;
        cout << x << " is a vec element" << endl;
        if(x==10){
            break;
        }
    }

    //calling fucntion with refrence
    int xxx = 20;
    cout << "xxx is " << xxx << endl;
    change(xxx);
    cout << "xxx is " << xxx << endl;
    changepoint(&xxx);
    cout << "xxx is " << xxx << endl;

    //structs
    struct structest s = {5.6,9.2};
    s.sx = 100.2; s.sy = 100.9;
    cout << s.sx << " | " << s.sy << " | " << s.sum() << " | " << sizeof(s) << endl;
    //you can have pointer to sturcts, like normal pointers really nothing special, in order to access stuff use -> instead of .
    stt ss ={5};
    cout << ss.x << endl;
    stt *ssp = &ss;
    cout << ssp->x << endl;

    //refrences, AKA EASY POINTERS, it can be the reurn of a function or argument
    int refrenced = 10;
    int &ref = refrenced;
    cout << "ref is: " << ref << endl;
    ref++;
    cout << "red is: " << ref << " and refrenced is: " << refrenced << endl;

    //basic pointers, btx int$ ptr = int *ptr
    int* ptr = &xxx;
    *ptr = 150;
    cout << "xxx is " << xxx << endl;
    int *nptr = NULL;
    cout << "the null pointers address is: " << &nptr << "they are usually used as int x; like for initializing" << endl;
    void* vptr = &xxx;
    cout << "the voic pointer is" << *(static_cast<int*>(vptr)) << endl;

    //MEMORY MANAGEMENT C STYLE YO
    //mighty malloc, calloc also exists and the only difference is that it initilizes the elements with 0 not NULL
    int *mptr = (int*)malloc(sizeof(int) * 5);
    if(mptr==NULL){
        cout << "no memory left, sorry" << endl;
        exit(0);
    }
    for(int i=0; i<5; i++){
        mptr[i] = i;
    }
    for(int i=0; i<5; i++){
        cout << mptr[i] <<endl;
    }
    //mighty realloc
    mptr = (int *)realloc(mptr, sizeof(int) * 6);
    mptr[5] = 5;
    for(int i=0; i<6; i++){
        cout << mptr[i] <<endl;
    }
    free(mptr);
    mptr=NULL; //this is for good practice, kinda crazy how easy that was, almost like i was overestimating this shit

    //MEMORY MANAGEMENT C++ STYLE, CAN'T MIX IT UP WITH C STYLE   
    int *cptr = new int(5);
    cout << "c++ pointer address: " << cptr << endl;
    cout << "c++ pointer value is: " << *cptr << endl;
    *cptr = 6;
    cout << "c++ pointer value is: " << *cptr << endl;

    int *cptra = new int[3] {1,2,3};
    for(int i=0; i<3; i++){
        cout << "cptra says: " << cptra[i] << endl;
    }
    delete mptr;
    delete[] cptra;

    //smart pointer, used wuth the c++ management style

    auto_ptr<int> aptr(new int(5));
    cout << "the auto pointer says: " <<  *aptr << endl;
    //auto pointer are shit, they change ownership behind teh scenes and you shouldn't use them

    auto uptr = make_unique<int>(5);//or with unique_ptr<int> as the data type instead of auto
    auto uptr2 = make_unique<int>();
    uptr2 = move(uptr);
    cout << "unique pointer1: " << *uptr << "unique pointer 2: " << *uptr2 << endl;
    //in unique pointer memory get dealocated/freed when the unique pointer is out of scope, unless it's been moved then it's when that one is out od scope

    auto sptr = make_shared<int>(5);
    auto sptr2 = make_shared<int>();
    sptr2 = sptr;
    cout << "shared pointers say: " << *sptr << sptr2 << endl;
    //memry gets freed when all the pointers are out of scope, i think

    shared_ptr<int> swptr = make_shared<int>(5);
    weak_ptr<int> wptr;
    wptr = swptr; 
    cout << "weak pointer says: " << wptr.lock() << endl;
    swptr.reset();
    cout << "weak pointer says: " << wptr.lock() << endl;//segmentation fault, the memory has been reset
    //weak pointers exists so we avoid the pointer cycle where memory can never be freed, just use it when two shared pointers point to each other

    //aight now for oop, which i don't even think i will use since structs can take functions, in second thoughts i will leave this for later
    //same goes for templates which are c++ generics










    //lambdas, which are basically true inline functions, they have a shit ton of features, can't be bothered to learn them now
    auto res = [] (int x){
        return (x*2);
    };
    cout << "the lambda says" << res(5) << endl;










    //goto exists, somehow, it gives assembly vibes
    cout << "Hello, World!" << endl;
    cout << hey() << endl;
    cout << yo() << endl;
    
    return 0; 
}

int yo(int k){
    int y = k;
    return y;
}

string hey(){
    return "hey people";
}

