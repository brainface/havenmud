/*  Convert a number of seconds to an integer array of the form
 *  ({ WEEKS, DAYS, HOURS, MINUTES, SECONDS }).  The optional second argument
 *  "unit" determines the largest unit to use.  For instance, a value of 1 to
 *  "unit" would cause (DAY*9) seconds to come out as 9 days, where it would
 *  normally come out as 1 week, 2 days without the second argument.  So a
 *  second argument of 1 causes DAY to be the largest unit used, 2 makes it
 *  HOUR, 3 makes it MINUTE.
 */

#define WEEK   604800
#define DAY    86400
#define HOUR   3600
#define MINUTE 60

varargs int* time_units(int seconds, int unit)
{
  int* units = ({ 0, 0, 0, 0, 0 });
  int  tmp   = 0;

  switch (unit)
  {
    case 0:
      units[0] = tmp = seconds/WEEK;
      seconds -= tmp*WEEK;

    case 1:
      units[1] = tmp = seconds/DAY;
      seconds -= tmp*DAY;

    case 2:
      units[2] = tmp = seconds/HOUR;
      seconds -= tmp*HOUR;

    case 3:
      units[3] = tmp = seconds/MINUTE;
      seconds -= tmp*MINUTE;
      break;

    default:
      error("Bad argument 2 to time_units().  Must be 1, 2, or 3.\n");
  }

  units[4] = seconds;

  return units;
}
