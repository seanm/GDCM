#include "gdcmVM.h"
#include <assert.h>

namespace gdcm
{

static const char *VMStrings[] = {
  "1",
  "2",
  "3",
  "4",
  "5",
  "6",
  "8",
  "16",
  "24",
  "1-2",
  "1-3",
  "1-8",
  "1-32",
  "1-99",
  "1-n",
  "2-2n",
  "2-n",
  "3-3n",
  "3-n",
  0
};

const char* VM::GetVMString(const VMType &vm)
{
  assert( vm <= VM_END );
  return VMStrings[(int)vm];
}

VM::VMType VM::GetVMType(const char *vm)
{
  for (int i = 0; VMStrings[i] != NULL; i++)
    //if (strncmp(VMStrings[i],vm,strlen(VMStrings[i])) == 0)
    if (strcmp(VMStrings[i],vm) == 0)
      return (VM::VMType)(i);

  return VM::VM_END;
}

bool VM::IsValid(const int &vm1, const VMType &vm2)
{
  bool r = false;
  assert( vm1 >= 0 ); // Still need to check Part 3
  // If you update the VMType, you need to update this code. Hopefully a compiler is
  // able to tell when a case is missing
  switch(vm2)
    {
  case VM1:
    r = vm1 == 1;
    break;
  case VM2:
    r = vm1 == 2;
    break;
  case VM3:
    r = vm1 == 3;
    break;
  case VM4:
    r = vm1 == 4;
    break;
  case VM5:
    r = vm1 == 5;
    break;
  case VM6:
    r = vm1 == 6;
    break;
  case VM8:
    r = vm1 == 8;
    break;
  case VM16:
    r = vm1 == 16;
    break;
  case VM24:
    r = vm1 == 24;
    break;
  case VM1_2:
    r = (vm1 == 1 || vm1 == 2);
    break;
  case VM1_3:
    r = (vm1 >= 1 && vm1 <= 3);
    break;
  case VM1_8:
    r = (vm1 >= 1 && vm1 <= 8);
    break;
  case VM1_32:
    r = (vm1 >= 1 && vm1 <= 32);
    break;
  case VM1_99:
    r = (vm1 >= 1 && vm1 <= 99);
    break;
  case VM1_n:
    r = (vm1 >= 1);
    break;
  case VM2_2n:
    r = (vm1 >= 2 && !(vm1%2) );
    break;
  case VM2_n:
    r = (vm1 >= 2);
    break;
  case VM3_3n:
    r = (vm1 >= 3 && !(vm1%3) );
    break;
  case VM3_n:
    r = (vm1 >= 3);
    break;
  default:
    assert(0); // shoult not happen
    }
  return r;
}

} // end namespace gdcm
