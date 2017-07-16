// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_POST_OFFICE;

static void create() {
  post_office::create();
  SetClimate("indoors");
  SetAmbientLight(50);
  SetTown("Karak");
  SetShort("Karak's Post Office");
  SetLong(
    "Karak's Post Office is a large building where citizens come "
    "to read and send mail by typing <mail> and following the "
    "instructions."
  );
  SetSmell( ([
    "default" : "There is a faint smell of paper and ink.",
  ]) );
  SetExits( ([
    "out" : KARAK_ROOM + "rd5.c",
  ]) );
}
