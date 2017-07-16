{\rtf1\ansi\ansicpg1252\deff0\deflang1033{\fonttbl{\f0\fswiss\fcharset0 Arial;}}
\viewkind4\uc1\pard\f0\fs20\par
#include <lib.h>\par
\par
inherit LIB_BBOARD;\par
\par
static void create() \{\par
  ::create();\par
  SetShort("a sage board");\par
  SetKeyName("board");\par
  SetId( (\{ "board" \}) );\par
  SetAdjectives( (\{ "sage" \}) );\par
  set_board_id("sage_bb");\par
  SetLong(\par
     "This board is the primary means of communication between the Sages "\par
     "on Haven. Please use it. "\par
  );\par
\}\par
\par
void init() \{\par
  ::init();\par
  if (base_name(environment(this_object())) != "/domains/staff/room/sage") \{\par
  eventDestruct();\par
  return;\par
  \}\par
\}\par
}
 