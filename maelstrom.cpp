#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>

using namespace std;

//checks argument validity and order to be passed to other functions
void checkArgs();

class File{
  private:
    int height;
    int width;
    string contents;
  
  public:
    /* Basic getters and setters */
    int getHeight(){
      return height;
    }

    int getWidth(){
      return width;
    }
    
    string getContents(){
      return contents;
    }

    void setHeight(int h){
      height = h;
    }

    void setWidth(int w){
      width = w;
    }

    void setContents(string c){
      contents = c;
    }

    /* I/O functions */
    //loads file into File object contents
    void load();

    //writes File object contents to output file
    void write();
};

//for funsies, checks run time
void time(clock_t t1, clock_t t2);





/* The big beef: main */
int main(int argc, char *argv[]){
  clock_t t1 = clock();

  File file;

  file.load();
  file.write();

  clock_t t2 = clock();
  time(t1, t2);
  return 0;
}




/* Function defintions */
void checkArgs(){

}

void time(clock_t t1, clock_t t2){
  float ticks = t2 - t1;
  float cps = ticks/CLOCKS_PER_SEC;
  string time = to_string(cps) + " seconds";
  cout << time << endl;
}

void File::load(){
  cout << "To be defined... : [" << endl;
}

void File::write(){
  cout << "To be defined... : [" << endl;
}
