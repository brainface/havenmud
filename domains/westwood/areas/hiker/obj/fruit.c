#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   string kn, sh, lg;
   array *di,*ad;
   meal::create();
   di = ({ "fruit" });
   ad = ({ "yummy" });
   SetMealType(MEAL_FOOD);
   SetStrength(8);
   SetMealMessages("The fruit is yummy.","$N eats some fruit.");
   SetMass(10);
   switch(random(7)) {
      case 0:
      kn = "kiwi";
      sh = "a ripe kiwi";
      di += ({ "kiwi" });
      ad += ({ "ripe" });
      lg = "The skin of the kiwi is slightly fuzzy and rather brown, "
           "but inside is a green area speckled with black seeds, and "
           "a white center.";
      break;
      case 1:
      kn = "red apple";
      sh = "a red apple";
      di += ({ "apple" });
      ad += ({ "red" });
      lg = "The apple is not completely red, but has a little bit of "
           "green on it.  It is ripe and tasty.";
      break;
      case 2:
      kn = "orange peach";
      sh = "a pale orange peach";
      di += ({ "peach" });
      ad += ({ "pale","orange" });
      lg = "The peach is a pale orange in color, but there is a small "
           "brown bruise to one side.  The rest of the peach looks "
           "delicious, however.";
      break;
      case 3:
      kn = "orange";
      sh = "a round orange";
      di += ({ "orange" });
      ad += ({ "round","orange" });
      lg = "The orange is large and round, with a nice orange peal "
           "on the outside.";
      break;
      case 4:
      kn = "yellow banana";
      sh = "a yellow banana";
      di += ({ "banana" });
      ad += ({ "yellow" });
      lg = "The banana is shaped like a crescent moon.  It has a "
           "couple small bruises, but nothing significant.";
      break;
      case 5:
      kn = "red strawberries";
      sh = "a bunch of red strawberries";
      di += ({ "strawberries","strawberry","berry","berries","bunch" });
      ad += ({ "bunch of","red","wild" });
      lg = "The strawberries are gathered into a bunch by the little "
           "green part coming out of the top.  They are all fairly "
           "small, but look like they are wild strawberries, and "
           "are very delicious.";
      break;
      case 6:
      SetKeyName("bunch of cherries");
      kn = "dark red cherries";
      sh = "a bunch of dark red cherries";
      di += ({ "bunch","cherries","cherry" });
      ad += ({ "bunch of","dark","red" });
      lg = "The cherries are very dark and red, just firm enough to not "
           "be spoiled but soft enough to be ripe.  Their stick-like "
           "stems are tied together to form a bunch.";
      break;
   }
   SetKeyName(kn);
   SetShort(sh);
   SetId(di);
   SetAdjectives(ad);
   SetLong(lg);
}
