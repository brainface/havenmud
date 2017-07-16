#include <lib.h>
#include <domains.h>
inherit AVERATH_LIB;

static void create(int x, int y) {
  ::create(-1,-1);
  SetTown("Averath");
  SetShort("by the Kylin Church");
  SetLong("The Kylin Church lies directly along the north side of this small "
          "path. To the east lies the Duke's Road, which runs north and south "
          "through Averath. Further south and west lie the plains of the Duchy, "
          "spread out in all their glory. The path here seems to be used mainly "
          "as an entrance to the church, which seems to be a quiet and humble "
          "structure of worship. The River Averath continues running from the "
          "northeast to the southwest here.");
  SetItems( ([
    "church" : "The Kylin Church is a quiet and humble wooden building.",
    "path" : "The path leads back to the Duke's Road.",
    "river" : "The blue waters of the River Averath are clean and clear.",
    ]) );
  SetItemAdjectives( ([
    "church" : ({ "sarythian", "quiet", "humble" }),
    ]) );
  SetEnters( ([
    "church" : AVERATH_CITY  "church",
    ]) );
}
