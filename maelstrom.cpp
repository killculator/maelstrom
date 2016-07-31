#include <iostream>
#include <string.h>
#include <fstream>
#include <sys/time.h>

using namespace std;

class File{
  private:
    int height;
    int width;
    string contents;
    string rName;
    string wName;
  
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

    string getRName(){
      return this->rName;
    }

    string getWName(){
      return this->wName;
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

    void setRName(string s){
      rName = s;
    }

    void setWName(string s){
      wName = s;
    }

    /* I/O functions */
    //loads file into File object contents
    void load(File *f);

    //writes File object contents to output file
    void write(File *f);
};

//for funsies, checks run time
void time(clock_t t1, clock_t t2);

//checks argument validity and order to be passed to other functions
void checkArgs(int argc, char *argv[], File *f);






/* The big beef: main */
int main(int argc, char *argv[]){
  clock_t t1 = clock();

  File file;
  File *filep = &file;

  //cout << strcmp(file->getName(), " ") << endl;

  checkArgs(argc, argv, filep);
  cout << "Reading " << file.getRName() << endl;
  cout << "Writing " << file.getWName() << endl;

  file.load(filep);
  //cout << file->getContents() << endl;

  file.write(filep);

  clock_t t2 = clock();
  time(t1, t2);
  return 0;
}




/* Function defintions */
void checkArgs(int argc, char *argv[], File *f){
  bool output = false;

  if (argv[1])
    f->setRName(argv[1]);

  for (int i = 0; i < argc; i++){
    cout << "at argv[" << i << "] argv = " << argv[i] << endl;
    if (!strcmp(argv[i],"-o")){
      f->setWName(argv[i + 1]);
      output = true;
    }

    //detect if no '-o' parameter was provided
    //to determine default file name,
    //supposedly date + filename
    if (!output){
      string name = "glitch-" + f->getRName();
      f->setWName(name);
    }

  }
}

void time(clock_t t1, clock_t t2){
  float ticks = t2 - t1;
  float cps = ticks/CLOCKS_PER_SEC;
  string time = to_string(cps) + " seconds";
  cout << time << endl;
}

void File::load(File *f){
  string contents;
  ifstream infile;

  infile.open(f->getRName());
  if (infile.is_open())
    while (infile.good())
      getline(infile, contents);

  f->setContents(contents);
  infile.close();
}

void File::write(File *f){
  ofstream outfile;

  outfile.open(f->getWName());
  outfile << f->getContents() << endl;

  outfile.close();
}
