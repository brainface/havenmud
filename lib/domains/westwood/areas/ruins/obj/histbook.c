/* Ancient Ruins History */

#include <lib.h>
string BlahRead();

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("metal book");
  SetShort("a small metal cased book");
  SetId( ({ "book", "metal book", "book" }) );
  SetAdjectives( ({  "small" , "cased" }) );
  SetLong("The outside case of this book is made of a thin metal which "
          "meets the requirements to protect the inlying pages inside. It "
          "appears in decent standard but it no way displays a brand new "
          "book from anything of modern standards. The pages on the inside "
          "have succumbed to water damage and have browned slightly but "
          "still this text written on the pages seem legible. Along the "
          "spine the title has been etched suggesting a hint of the contents "
          "that lie inside, It reads 'Ivory Castle -- Westwood Jewel' in "
          "familiar ancient Muezzin style.");
  SetMass(5);
  SetValue(25);
  SetRead( (: BlahRead :) );
  SetMaterial( ({ "natural" }) );
 }
string BlahRead() {
   object who = this_player();
   if((who->GetLanguageLevel("Oiseau") > 70+random(20))){
      who->eventPrint(
             " After we, the chosen of Amelia were created dawning the "
          "first GodsWar, our hearts sank heavily. Entering this world "
          "of greed and despair would bring down any Muezzin cub. Before "
          "Soleil was even a whisper our knowledge of the world would "
          "have to reach towards the older races of Kailie.\n\n"
          "  It was brought before the council of elders to expand home, "
          "to not consolidate our entire army huddled. My Eclat brother "
          "Sembocyle and I, we volunteered to establish the Ivory castle "
          "and provide Amelia's children with shelter and quarters in "
          "our infancy.\n\n"
          "  Brother Sembocyle funded this castle to also be created as a "
          "testament of all who had fallen in the first Godswar. It would "
          "compliment us as an outpost and a relative safe place to establish "
          "a reservoir barracks on the ground. Sembocyle had also crafted "
          "weapons and armour to those who have already been assigned. I "
          "spent my time with my crew designing these sturdy white walls "
          "and digging the moat with my bare paws.\n\n"
          "  After the team and I were completed building everything, "
          "the Ivory castle had turned into its own entity. The troops "
          "which frequently rotated here from assignments enjoyed themselves. "
          "Visitors and merchants which stopped by often to trade their "
          "goods and tell us news of the outside world.\n\n"
          "  With the ever powerful Immortals who roam this land, who command "
          "sheer armies at their disposal, we would have to protect ourselves. "
          "I pray we shall never need to use it in war and my post here with "
          "my Eclat brethren would be an easy assignment. Long live the "
          "Ivory castle unless we find a more permanent settlement.\n\n"
          "           ~Delrakhorune Leav, the Architect");
      return "";
   }
   who->eventPrint("The pages are written in a language that is "+
                   "unknown to you.");
   return "";
}   