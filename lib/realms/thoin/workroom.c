#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("The Truth in Nothingness");
  SetLong("There is nothing, There will be nothing, We are nothing. "
    "We are meaningless as we cannot understand the meanings that are "
    "inherit in the lies told in the truth. Our perception allows us to believe "
    "in a reality and such we create a god to overlook our own existence. "
    "However if we ourselves created god by perceptions of what truth and "
    "reality is then couldn't one kill god by believing that there is no "
    "such thing as truth and that reality doesn't exist except to playcate "
    "our feeble minds."
  );
  SetItems( ([
    ({ "nothing" }) : "By looking at nothing does that mean we are trying "
    "to make it exist, thinking if we see it then it shall exist or that "
    "our search for it will create it. Perhaps the search and desire to find "
    "nothing is what in the ends creates nothing.",
    ({ "meanings", "meaningless" }) : "Why do we attempt to do things we "
    "will end with nothing, if our journey has no meaning then the result "
    "of the journey will be meaningless.",
    ({ "truth", "lies" }) : "Is there a difference between lies and truth? "
    "Isn't it our own perceptions that control what we define as truth and "
    "lies, there is no such thing as natural truths or common truths. It "
    "is our distortion of reality that causes us to believe there are "
    "differences found in the two.",
    ({ "god" }) : "If we created god through our own perceptions then one "
    "can reason that we can kill god and such one could presume we have "
    "killed god already but upon his death we lost the definition that holds "
    "our thoughts together to form a reality. In absence of god we are nothing "
    "with god existing we are nothing as he never did exist except in our "
    "own thoughts and lack of reality.",
    ({ "existence" }) : "Do we truly exist is what I want to ask but "
    "how can I? If we do not exist then why bother asking the question "
    "in the first place and if we do existence then pondering if we do "
    "has no meaning. A better question would be to ask if reality "
    "exists or is just a by product of our own existence.",
    ({ "perception" }) : "If we do not exist or rather no one else exist "
    "then does that mean our own perception is that of absolute truth? "
    "But if truth is a lie created by perceptions and there is only one "
    "possible perception of reality does that mean our own perceivable "
    "reality is a lie created by our own perception. If so then all we "
    "know is a lie since our own thoughts and mind give us lies.",
    ({ "minds" }) : "The object of our destruction. We use them to think "
    "but by doing so we end up destroying our own thoughts of reality. "
    "In the end our minds have destroyed reality and ourselves but they "
    "never existed in the first place so how did they destroy anything?",
  ]) );
  SetListen( ([
    "default" : "How can you hear anything if you don't exist?",
  ]) );
  SetSmell( ([
    "default" : "Would there be smells if there was no reality?",
  ]) );
  SetObviousExits("");
  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "east" : STD_AREA "room/basic",
  ]) );
}
