#include "val_chooser.h"
#include "../variable.h"

int val_chooser::get_val(IntVarObj* __v) const
{
  return __v->inf();
}

