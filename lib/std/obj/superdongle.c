#include <lib.h>

inherit LIB_ITEM;

int suckage();
int blah(string cmd);
int GetInfo();

string *verbs = distinct_array( ({ "visit", "spam", "glue", "grope", "touch",
  "cough on", "stare at", "puke on", "pinch", "paint", "fondle", "watch",
  "grin evilly at", "lick", "bounce around", "shake", "slurp", "dance around",
  "feel", "touch", "lift", "drop", "expose yourself to", "twist", "seduce",
  "rent", "talk dirty to", "make fun of", "sell", "buy", "videotape", "slap",
  "have an orgasm with", "fondle", "jump on", "clean", "shower with", "know",
  "encourage", "massage", "rub", "cook a Thanksgiving turkey for", "explain",
  "scrub the toilet for", "rub yourself with", "disinfect", "think about",
  "oops, you just blew up", "defeat", "spot", "sit on", "sleep with", "spank",
  "undress", "undress for", "ride", "hug", "embrace", "fear", "run into",
  "drool on", "yell at", "give yourself to", "worship", "clean", "eat", "taunt",
  "spit on", "flash", "sleep on", "sleep under", "sleep next to", "poke",
  "sit on", "take advantage of", "feed", "skinnydip with", "poke", "shave",
  "shave over", "insult", "compliment", "buy a gift for", "have someone touch",
  "get someone to touch", "photograph", "slurp", "tease", "worship", "threaten",
  "squeeze", "smack", "tackle", "have an affair with", "hide", "curse", "lure",
  "bark at", "enchant", "kiss", "destroy", "probe", "bonk", "pounce on", "wash",
  "jump out of an airplane at 10thousand feet and land on",  "dream about",
  "use an \"APPROVED\" stamp on", "drop out of school because of", "act like",
  "go braindead and drool on", "pretend to be", "have a fantasy about",
  "learn that the meaning of life is all about", "throw rice at",
  "learn that the meaning of life is all about undressing for",
  "discuss sex before marriage with", "discuss celebacy with",
  "offer a high paying job to" }) );
  
string *things = ({ "the", "your", "my" });

string *adjectives = distinct_array( ({ "sloppy", "hairy", "evil", "juicy",
  "polkadot", "bright orange", "lusty", "huge", "tiny", "stupid", "attractive",
  "crazy", "slutty", "sexy", "powerful", "weak", "dangerous", "horny", "wet",
  "poor", "moldy", "slippery", "sticky", "bulging", "incredible", "dirty",
  "filthy", "clean", "ugly", "beautiful", "handsome", "clammy", "skinny",
  "fishy", "smelly", "stinky", "stinking", "intelligent", "lost", "sick",
  "unbelievably gigantic", "sensitive", "whiny", "super loud", "greasy",
  "excellent", "fresh", "crusty", "creamy", "saucy", "drunken", "graceful",
  "tasteful", "tasteless", "happy", "creepy", "amazingly good looking", "yummy",
  "deep", "honorable", "immature", "rude", "tired", "lowly", "hungry",
  "squishy", "lonely", "addictive", "useless", "angry", "Sab-like", "Zedd-like",
  "anal", "stuck up", "moronic", "well endowed", "idiotic", "famous",
  "glistening", "shiny", "talking", "squirming", "charismatic", "ass kicking",
  "square dancing", "sexually frustrated", "hard", "slick", "slippery",
  "bungling", "clumsy", "oafish", "smooth", "unpredictable", "excited",
  "exciting", "desirable", "resentful", "amusing", "aggravating"}) );

string *nouns = distinct_array( ({ "breasts", "breast", "ass", "toes",
  "fingers", "tires", "joystick", "sextoy", "pumpkin pie", "boots", "chair",
  "doorknob", "stereo", "sex slave", "president", "genitals", "computer",
  "floppy disk", "car", "poster", "lampshade", "Zedd", "power tool", "old man",
  "paperclip", "slice of bread", "bowl of lime jello", "camera", "biceps",
  "arms", "legs", "hair", "pants", "underwear", "panties", "teachers",
  "professors", "doctor", "lunch bag", "can of beans", "collection of porn",
  "sausage", "nose", "wrench", "firehose", "book", "zipper", "condom", "Malak",
  "shift lever", "christmas tree", "shingles", "sailor", "great grandfather",
  "clock", "\"Fuck You\" hat", "airplane", "skirt", "dress", "clothing",
  "eyeballs", "eyes of Zedd", "Malak", "Morgoth", "slurpee", "hotdog",
  "\"Sex Instructor.  First lesson free.\" hat", "bong", "fishing pole",
  "orgasm", "tongue", "Empire State Building", "shag carpet", "hair stylist",
  "B-grade movie", "nipples", "prom queen", "prom king", "homecoming queen",
  "homecoming king", "computer geek", "boss", "Ferrari", "Porsche",
  "electric guitar", "third nipple", "Portia", "Kyla", "hamburger",
  "superdongle", "coat hanger" }) );

string *that = ({ "!", "!", ".", ".", "?", "!!!" });

string *colors = ({ "RED", "GREEN", "BLUE", "YELLOW", "MAGENTA", "CYAN",
                    "ORANGE", "WHITE" });

static void create()
{
  item::create();
  SetKeyName("superdongle");
  SetId( ({ "super dongle", "dongle" }) );
  SetAdjectives( ({ "super" }) );
  SetShort("a super dongle");
  SetLong("There is no dongle here.");
  SetValue(0);
  SetMass(2000000);
  SetInvis(1);
  set_heart_beat(85);
}

void init()
{
  item::init();
  add_action( (: blah :), ({ "getit" }));
  add_action( (: GetInfo :), ({ "getinfo" }));
}

int suckage()
{
  string phrase = "%^BOLD%^";
  if (!(creatorp(environment()))) return 0;
  phrase += colors[random(sizeof(colors))];
  phrase += "%^";
  phrase += capitalize(verbs[random(sizeof(verbs))]);
  phrase += " ";
  phrase += things[random(sizeof(things))];
  phrase += " ";
  phrase += adjectives[random(sizeof(adjectives))];
  phrase += " ";
  phrase += nouns[random(sizeof(nouns))];
  phrase += that[random(sizeof(that))];
  phrase += "%^RESET%^";
  environment()->eventPrint(phrase);
  return 0;
}

static void heart_beat()
{
  suckage();
}

int blah(string cmd)
{
  suckage();
  return 1;
}

int GetInfo()
{
  this_player()->eventPrint("Your copy of the superdongle has:\n" +
                            sizeof(distinct_array(verbs)) + " verbs,\n" +
                            sizeof(distinct_array(adjectives)) + " adjectives,\n"
                            "and " + sizeof(distinct_array(nouns)) + " nouns.\n"
                            "There are " +
                            (sizeof(distinct_array(verbs)))*(sizeof(distinct_array(adjectives)))*(sizeof(distinct_array(nouns)))
                            + " possible phrases, not counting "
                            "\"the, your, my\".");
  return 1;
}
