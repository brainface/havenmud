#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   string thecolor,ansicolorstuff;
   switch(random(6)){
      case 0:
      thecolor = "red";
      ansicolorstuff = "%^RED%^";
      break;
      case 1:
      thecolor = "blue";
      ansicolorstuff = "%^BLUE%^";
      break;
      case 2:
      thecolor = "purple";
      ansicolorstuff = "%^MAGENTA%^";
      break;
      case 3:
      thecolor = "white";
      ansicolorstuff = "";
      break;
      case 4:
      thecolor = "yellow";
      ansicolorstuff = "%^YELLOW%^";
      break;
      case 5:
      thecolor = "black";
      ansicolorstuff = "";
      break;
   }
   armour::create();
   SetSize(SIZE_SMALL);
   SetKeyName(ansicolorstuff + thecolor + "%^RESET%^ shirt");
   SetShort("a " + ansicolorstuff + thecolor + "%^RESET%^ shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ thecolor }) );
   SetLong("The shirt is made of an average " + ansicolorstuff + 
           thecolor + "%^RESET%^ cloth.");
   SetMass(30);
   SetValue(35);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SHIRT);
   SetDamagePoints(155);
   SetProtection(SLASH,2);
   SetProtection(BLUNT,2);
   SetProtection(PIERCE,2);
   SetProtection(HEAT,1);
   SetProtection(COLD,4);
   SetProtection(ACID,1);
   SetMaterial( ({ "textile" }) );
  SetWarmth(10);
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "textile working" : 1,
                       "armour smithing" : 1,
                  ]) );
}
