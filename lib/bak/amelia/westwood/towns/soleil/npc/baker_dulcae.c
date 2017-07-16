#include <lib.h>
inherit LIB_BARKEEP;
#include "../soleil.h"

static void create() {
   barkeep::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Dulcae");
   SetShort("Dulcae, the baker");
   SetId( ({ "Dulcae","baker","muezzin","lady" }) );
   SetAdjectives( ({ "muezzin","short","fat" }) );
   SetLong("Dulcae is a short fat muezzin lady who has big hands "
           "and a happy demeaner.  She stands straight and tall, "
           "almost as if she wants to be a few centiments higher "
           "into the air.  Her twinkling face has the look of "
           "many hours of cooking behind it, preparing for the "
           "days' sales.");
   SetGender("female");
   SetRace("muezzin");
   SetLevel(13);
   SetClass("valkyr");
   SetSkill("bargaining",1);
   SetLocalCurrency("cuicui");
   SetMenuItems( ([
                    "meza" : S_OBJ + "meza",
                    "cinnamon roll" : S_OBJ + "roll_cinnamon",
                    "buttery croissant" : S_OBJ + "croissant",
                    "fresh bread" : S_OBJ + "bread_fresh",
                    "banana bread" : S_OBJ + "bread_banana",
                    "cinnamon bread" : S_OBJ + "bread_cinnamon",
                    "slice banana bread" : S_OBJ + "bread_banana_slice",
                    "slice cinnamon bread" : S_OBJ + "bread_cinna_slice",
               ]) );
   SetMorality(230);
   SetAction(7, ({
                   "!speak in oiseau My meza is known all over Soleil.  "
                      "Muezzins everywhere are drinking it.  It's "
                      "a lot like coffee, only better.",
                   "!speak in oiseau I've made the most wonderful "
                      "bread to sell!  Some plain, fresh bread, sold "
                      "by the loaf, and banana bread and cinnamon "
                      "bread, sold by the loaf or slice!",
                   "!speak in oiseau My buttery croissants are "
                      "simply exquisite!  Not to be missed!",
                   "!speak in oiseau If you've ever had a cinnamon "
                      "roll and thought it was good, than "
                      "mine are a must!  Try one!",
                   "!emote putzes around behind the counter, cleaning "
                      "up invisible messiness and making the "
                      "food look even nicer than it already is.",
              }) );
   AddTalkResponse("meza","Meza is coffee, only its much, much, better.  "
                   "If you like the caffeine, you've got to try it!");
   SetReligion("Eclat","Eclatish");
   SetFriends( ({ "Tia","Aegri Portare","Alamus","cemetary worker",
                  "Soleil citizen","Oppugno","shaggy dog","Sorgan",
                  "entrance guard","Iuvo","Fossis","Kiee","Miserum" }) );
}
