#ifndef UTIL_H
#define UTIL_H

#include <unistd.h>
#include <iostream>

/// ============================================== ///
///             Definició operacions               ///

namespace util {

  // netejar pantalla
  void neteja() {
    char esc=27;
    std::cout<<esc<<"[2J"<<esc<<"[1;1H";
  }
  
  // esperar t segons
  void espera(float t) { 
    useconds_t s=t*1000000;
    usleep(s);
  }  
}

#endif
