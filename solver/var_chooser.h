#ifndef _VAR_CHOOSER
#define _VAR_CHOOSER

#include <vector>
#include <limits.h>

class IntVarObj;
class var_chooser
{
  
private:
  std::vector<IntVarObj*> _vars;
  
public:
  var_chooser(std::vector<IntVarObj*>);
  IntVarObj* get_var();
};



#endif
