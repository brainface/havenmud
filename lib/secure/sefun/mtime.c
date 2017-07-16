#include <daemons.h>

varargs string mtime(int when)
{
  if (!when) when = time();
  return sprintf("%s %s %s %02d:%02d, Year %d (%s)",
    SEASONS_D->GetDayName(when),
    SEASONS_D->GetMonth(when),
    "the " + SEASONS_D->GetDay(when) + ordinal(SEASONS_D->GetDay(when)),
    SEASONS_D->GetHour(when),
    SEASONS_D->GetMinutes(when),
    SEASONS_D->GetYear(when),
    SEASONS_D->GetSeason(when));
}
