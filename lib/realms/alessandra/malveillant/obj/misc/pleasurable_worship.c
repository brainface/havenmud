#include <lib.h>

inherit LIB_ITEM;

static void create() {
::create();
SetKeyName("pleasureable worship");
SetShort("a black cloth book");
SetId(({ "pleasurable worship", "book", "book of faith", "soirin book" }));
SetAdjectives( ({ "black", "cloth" }) );
SetLong(
        "Bound in soft black cloth, this book is extremely soft to the"
        " touch. It is small enough to fit comfortably into a pocket"
        " and has clear golden letters at the bottom of the cover"
        " denoting the title: Pleasurable Worship."
        );
SetRead("default", 
   
         "  Pleasurable Worship: How To Please the Mistress of Seduction \n"
         "            by High Priestess Tallia Vestilanti \n\n"
         "    The Adoration of Alessandra is one of simple actions. It is \n"
         " the love of yourself. It is the love of your appearance. It is \n"
         " the love of your senses. It is the love of being. She adores you \n"
         " and wants you to be happy in all that you do, that is why she has \n"
         " granted us such pleasures in life. For our pleasure and our \n"
         " happiness Our Mistress has permitted us a free range of actions, \n"
         " nothing shall displease Her so long as it brings you pleasure and \n"
         " happiness and in turn, brings Her pleasure and happiness. \n\n"
         "    It is the sensual side of Our Mistress that appeals to most of \n"
         " her adherents. For She is the symbol of ultimate satisfaction in \n"
         " every aspect of life but especially in the bed chambers. The \n"
         " faithful of Alessandra should not fear what others may consider \n"
         " taboo and inappropriate in terms of sexual activity, for She \n"
         " delights in creativity and exploration. It is, therefore; our \n"
         " responsibility to be ardent and imaginative in our approaches and \n"
         " practices in the bed chambers. Pleasure is Her goal, and for the \n"
         " faithful, it is the path of piety. \n"
     );

}

varargs mixed eventRead(object who, string str) {
if (who->GetReligion() == "Soirin" && who->GetBlessed() < 1) {
  who->AddBlessed(5);
  return ::eventRead(who, "default");
  }
  return ::eventRead(who, "default");
}
