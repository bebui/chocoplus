#include "val_chooser.h"
#include "../variable.h"

int val_chooser::get_val(IntVarObj* __v)
{
  return __v->inf();
}