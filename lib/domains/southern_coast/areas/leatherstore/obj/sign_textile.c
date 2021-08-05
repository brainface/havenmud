#include <lib.h>ed 
inherit LIB_ITEM;


static void create() {
   item::create();
   SetShort("an instructive sign");
   SetRead("default",
     "%^BOLD%^CYAN%^\n"
     "OOC:
     Here's the craft Process:
     Farm or acquire a material that can be rendered into 
     thread or yarn (flax, cotton, or hemp)
     'Attach' your flax to a spinning wheel.
     'Spin' thread or yarn with the wheel.
       (make at least two yarns and one thread.)
     'Attach' two yarns to a loom.
     'Weave' checked with loom (you can weave a few other patterns)
       to produce a piece of fabric.
     Now 'Sew' [size] sock from fabric with thread.

     Again!
     Farming produces plants.
     Spinning wheels spin yarn and thread from certain plants.
     Looms weave fabric from yarn.
          You can sew clothing anywhere with fabric and thread.

     *Dyeing: You can dye thread/yarn now but it won't matter."
     "%^RESET%^\n"
   );

   SetLong(
     "A well-carved wooden sign is planted in the ground here. "
     "Carefully stenciled painted letters mark the front. "
   );
   SetLong( GetLong() + GetRead("default") );
   SetId( ({"sign"}) );
   SetMaterials( ({"wood"}) );
   SetAdjectives( ({ "instructive" }) );
   SetKeyName("sign");
   SetPreventGet("The sign is securely moored in the ground.");
}

