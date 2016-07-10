#include <unistd.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sys/time.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <fstream>

#define BUFSIZE 100

/* program to glitch pictures
 * TODO:
 * []bitmap / single file support
 *  *[X]extention recognition
 *  *[X]read file
 *  *[]one glitch method
 *  *[]bitmap output
 * []multiple file support
 * []multiple extension support
*/


using namespace std;

//fun crap, for runtime info
float chrono(clock_t t1, clock_t t2){
  float ticks = t2 - t2;
  float cps = (float)ticks/CLOCKS_PER_SEC;
 
  string calcs = to_string(ticks) + " ticks, or " + to_string(cps) + " seconds";
 
  return (float)(t2 - t1)/CLOCKS_PER_SEC;
}

string load(char *argv[]){
  string contents;
  ifstream infile;
  infile.open(argv[1]);
  if(infile.is_open())
    while(infile.good())
      getline(infile, contents);


  infile.close();
  return contents;
}

//runs a check on the extension, making sure the file is a bitmap
//maybe a more secure way of doing this?
string getExt(int argc, char *argv[]){
  if(argv[1] != NULL){
    size_t nameSize = strlen(argv[1]);
    string ext = "";

    for(int i = 0; i < nameSize; i++){
      if(argv[1][i] == '.'){
        for(int k = i; k < nameSize; k++){
          ext += argv[1][k];
        }
      }
    }

    if(ext != ".bmp"){
      cout << ext + " file format not supported (yet?), sorey m8" << endl;
      exit(1);
    }
    else 
      return ext;
  }
  else{
    cout << "no file specified, try './glitch somefile.bmp'" << endl;
    exit(2);
  }
}

int main(int argc, char *argv[]){
  clock_t t1, t2;
  t1 = clock();
  //cout << "clock1 good" << endl;
  getExt(argc, argv);
  //cout << "getExt good" << endl;
  load(argv);
  //cout << "load good" << endl;
  t2 = clock();
  cout << chrono(t1, t2) << endl;
  
  return 0;
}
