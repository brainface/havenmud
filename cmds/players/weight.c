/* weight.c, gives a clue on how much a person is carrying,
  by zaf@haven */

#include <lib.h>
inherit LIB_DAEMON;
string mesg;
float percent_carried;
int int_percent_carried;
mixed cmd()
        {
        if (creatorp(this_player()))
                {
                return "You currently weigh 6 tons, get on a diet, fast.";
                }
        else 
                {
                percent_carried = to_float(this_player()->GetCarriedMass()) / to_float(this_player()->GetMaxCarry());
                int_percent_carried = to_int(percent_carried * 100);
                switch (int_percent_carried)
                        {
                        case 0 : mesg = "You are carrying nothing of "
					"noticable weight.";
                                break;
                        case 1..20 : mesg = "You barely notice the "
					    "weight of your belongings.";
                                break;
                        case 21..40 : mesg = "You are slightly encumbered "
					     "from the weight of your items.";
				break;
                        case 41..60 : mesg = "%^CYAN%^The weight of your "
					     "items has become a minor "
					     "annoyance to you.";
				break;
                        case 61..73 : mesg = "%^BLUE%^The burdensome "
					     "weight of your items makes "
					     "moving a lot more difficult.";
				break;
                        case 74..90 : mesg = "%^YELLOW%^You are carrying "
					     "so many things, you doubt "
					     "you can carry much more.";
				break;
                        case 91 .. 99 : mesg = "%^RED%^Just the "
					       "energy used to carry your "
					       "items is making you sweat.";
				break;
                        case 100 : mesg = "%^RED%^BOLD%^You are carrying "
					  "so many things, that you doubt "
					  "you can carry any more.";
				break;
                        }
                return mesg; 
  
                }
        }

void help()
        {
        message("help", "Syntax: <weight>\n\n"
                "Gives you an idea on how much the weight you are currently "
                "carrying.\n\n"
                "See also: money, skills, stats, status",
                this_player());
        }
