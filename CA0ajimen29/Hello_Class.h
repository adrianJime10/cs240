#include <iostream>

using namespace std;

class Hello_Class {
   public:
      Hello_Class(int i) {
         if (i == 0) {
            output_string = "Hello C++ Data Structures, from Adrian!";
         } else {
            output_string = "Hello Data Structures!";
         }
      }
      void print_hello();
   private:
      string output_string;
};
