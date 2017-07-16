// Container for wedding present for luna :)
#include <lib.h>
#include <std.h>
inherit LIB_STORAGE;
 
void AddGloves();
 
static void create()
{
	storage::create();
	SetShort("a small exquisite box");
	SetKeyName("box");
	SetId( ({ "box" }) );
	SetAdjectives( ({ "small, exquisite" }) );
	SetLong(
	  "This small box is made from some of the finest rosewood available. "
	  "It is inlaid with soft, red velvet and has a sparkling silver latch."
	  );            
	SetMass(10);
	SetCanClose(1);
	SetClosed(1);
	SetMaxCarry(10);
	SetPreventGet(0);
	SetCanLock(0);
	SetOpacity(100);
	SetMaterial( ({ "wood" }) );
}