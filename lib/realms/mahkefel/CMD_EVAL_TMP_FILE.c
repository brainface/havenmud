#include <lib.h>
#include <daemons.h>
#include <objects.h>
#include <commands.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <std.h>
inherit LIB_ITEM;
mixed eval() { sscanf("-c -l --minlevel 20","--minlevel%s%d",0); }
