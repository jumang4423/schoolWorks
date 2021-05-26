package se1ex12.src;

/*
 * University of Aizu [Introduction to Software Engineering] Exercise material
 *
 * Class: MyCalendar
 *
 * Date: 2015/05/04
 *
 * author: University of Aizu & Nihon Unisys, Ltd. Technical Research Institute
 * 
 * This code may be used without modification
 */

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MyCalendar {

  public static final String DATE_FORMAT = "yyyy-MM-dd";

  public static String formatDate(Date date) {
    SimpleDateFormat sdf = new SimpleDateFormat(DATE_FORMAT);
    return sdf.format(date);
  }

  public static Date getDate(String s) {
    Date date;
    SimpleDateFormat sdf = new SimpleDateFormat(DATE_FORMAT);
    try {
      sdf.setLenient(false);
      date = sdf.parse(s);
    } catch (ParseException e) {
      date = null;
    }
    return date;
  }
}
