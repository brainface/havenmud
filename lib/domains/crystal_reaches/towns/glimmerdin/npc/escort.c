#include <lib.h>
#include "../path.h"
inherit LIB_NPC;
int requestTour(object who, string what);
int eventTour(object *who, int iter);
string *Tour = ({
	"speak Welcome to Glimmerdin.  I'll be happy to show you around.",
	"tourooc Please, don't use your keyboard while you follow the tour "
	    "guide. You can use <look> to see the room again if you like.",
	"speak This is the Keep, the central governmental building in town. "
	      "Here, people can come and request citizenship into our great "
	      "town. Also, there is a news board here with news posted by "
	      "the citizens of Glimmerdin. It might be a good idea to check "
	      "up on that once in a while.",
	"go out",
	"speak This is the center of the Great Hall of Glimmerdin. Here you "
	      "can find many interesting things, including a shop which you "
	      "can <enter shop> and look around. Also here is a deep pool "
	      "which you could <drink from pool>, and you are also able to "
	      "<fish> here if you have a fishing pole. Kind of an interesting "
	      "center of town!",
	"go north",
	"speak This is the northern part of the Great Hall. While still a very "
	      "busy part of town, this area has less traffic than the Center. "
	      "Off to the north is the Cathedral of Kylin. You could <enter "
	      "cathedral> if you wanted. Lying to our east is the Glimmerdin "
	      "cemetery. A quiet place, this is where you will appear should you "
	      "ever die while walking Kailie. Should you find yourself undead, it "
	      "is best if you enter the church and <ask healer to resurrect me>. ",
	"enter church",
	"speak Welcome to the Cathedral of Kylin. Normally, Torun Stonebone is "
	      "here extolling the faithful to prayer. If you wanted, you could "
	      "<ask torun to join clerics> to begin your path on a career of "
	      "pious learning. Once you did that, you would also need to <ask "
	      "torun to teach> the various spells. (You can find those spells "
	      "in \"help allspells\" and compare that list to your new skills.)",
	"speak Normally, there is a healer here. The healer can perform many "
	      "actions for you, including restoring lost limbs, healing damage, "
	      "and even resurrecting you should you die. Be familiar with his "
	      "location, as it could become important later.",
	"go out",
	"go west",
	"speak This is the western part of the Great Hall. It receives even less "
	      "traffic than the northern edge, but is still important. Built along "
	      "the cavern wall to the west is an inn, which you can again <enter> "
	      "if you get hungry. Lying to our north is the Glimmerdin Orchestral "
	      "Hall, where you could begin a career as a Bard.",
	"go east",
	"go east",
	"speak This is the cemetery. While important, I actually brought you here so "
	      "you would see the shrine to the north. That is the home of the Kylin "
	      "Knights Templar of Glimmerdin. Their chivalrous ways are not for the "
	      "faint of heart. Most of them are mere knights, but some aspire to and "
	      "achieve the status of Paladin of Kylin, which requires study, "
	      "contemplation, and immense work.",
	"go west",
	"go south",
	"enter hall",
	"speak This is the training hall of the Glimmerdin Militia. Civak Axethrower "
	      "is usually here, and one could <ask civak to join fighters> if you want"
	      "ed to start a career as a combat-oriented member of society.",
	"smirk",
	"go out",
	"go south",
	"speak This is the southern edge of the Great Hall, which includes the entrance "
	      "to the town and the first signs of civilization. From here, you can <enter> "
	      "two very important buildings.  The first is the Glimmerdin Bank, where you "
	      "will be able to exchange all the foreign coins you find into good, solid, "
	      "nuggets. You'll also be able to save your money there, which is very good "
	      "in case you should happen to die. (For more information, you should <help "
	      "banking>.)",
	"speak The other building of note is the post office.",
	"enter office",
	"speak In here, you can send and receive mail from other people on Kailie. You "
	      "can also read the news board, which includes important announcements from "
	      "the Immortals and an Out-Of-Character discussion. To read the news, simply "
	      "<news>",
	"go out",
	"go north",
	"enter keep",
	"speak Thank you for taking my tour!",
	});
object *Tourists = ({ });
int TourCount = 0;

static void create() {
  ::create();
  SetKeyName("tour guide");
  SetId( ({ "dwarf", "guide" }) );
  SetAdjectives( ({ "tour", "dwarf", "dwarven" }) );
  SetShort("a dwarven tour guide");
  SetLong(
    "Attired like a diplomat, but built like a warrior, this "
    "gentleman here is one of those few dwarves courteous enough "
    "to be a visitor's guide. If asked, he would show any young "
    "dwarf around Glimmerdin."
    );
  SetRace("dwarf");
  SetClass("merchant");
  SetLevel(35);
  SetMorality(100);
  SetGender("male");
  SetCurrency("nuggets", random(20)+1);
  SetAction(90, ({
  	"!speak If you'd like, you can <request tour from tour guide>",
  	"!speak I'd be happy to show you around town.",
  	"!speak Glimmerdin is a very complex town, let me show you.",
  	"!speak Welcome to Glimmerdin!",
    }) );
  AddChannel( ({ "tourooc" }) );
  AddRequestResponse("tour", (: requestTour :) );
  SetLimit(1);
  set_heart_beat(5);
}

void heart_beat() {
	::heart_beat();
	if (sizeof(Tourists))
	  eventTour(Tourists, TourCount);
}

mixed eventAsk(object who, string what) {
	mixed t = ::eventAsk(who, what);
	eventForce("speak If you'd like me to take you on a tour, please just "
	           "<ask guide for tour>.");
	return t;
}

mixed eventRequest(object who, string what) {
	mixed t = ::eventRequest(who, what);
	if (what != "tour") {
		eventForce("speak If you'd like me to take you on a tour, please "
		           "just <ask guide for tour>!");
		           }
	return t;
}

int requestTour(object who, string what) {
	if (what != "tour") {
		eventForce("speak Did you want a tour? If so, <request tour from tour guide>");
		return 1;
	}
	eventForce("speak Wonderful!  I'll show you around!");
	who->eventForce("follow tour guide");
	eventForce("lead " + who->GetKeyName());
	Tourists += ({ who });
	who->AddChannel( ({ "tourooc" }) );
	SetAction(0, ({ }) );
	set_heart_beat(20);
	return 1;
}

int eventTour(object *who, int num) {
	if (num < sizeof(Tour)) {
	  eventForce(Tour[num]);
	  TourCount++;
	}
	if (TourCount == sizeof(Tour)) {
		eventForce("wave");
		foreach(object tourist in Tourists) {
			if (!tourist) continue;
                        if (environment() != environment(tourist)) continue;
			if (!(tourist->GetQuestCompleted("Glimmerdin Tour"))) {
			  tourist->AddQuest("the Glimmerdin Tourist", "Glimmerdin Tour");
			  tourist->AddDevelopmentPoints(2);
			  tourist->RemoveChannel( ({ "tourooc" }) );
			  set_heart_beat(5);
			  }
			}
		Tourists = ({ });
		TourCount = 0;
		SetAction(90, ({
  	  "!speak If you'd like, you can <request tour from tour guide>",
  	  "!speak I'd be happy to show you around town.",
  	  "!speak Glimmerdin is a very complex town, let me show you.",
  	  "!speak Welcome to Glimmerdin!",
      }) );
		}
	return TourCount;
}

		
