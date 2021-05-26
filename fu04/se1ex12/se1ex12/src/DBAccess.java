package se1ex12.src;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

/*
 * University of Aizu [Introduction to Software Engineering] Exercise material
 *
 * Class: DBAccess
 *
 * Date: 2018/07/01
 *
 * author: University of Aizu & Nihon Unisys, Ltd. Technical Research Institute
 *
 * This class may be used without modification
 */

public class DBAccess {
  Connection con;

  public DBAccess() throws ClassNotFoundException, SQLException {
    Class.forName("org.apache.derby.jdbc.EmbeddedDriver");
    Properties prop = new Properties();
    prop.put("create", "true"); 

    con = DriverManager.getConnection("jdbc:derby:SE1ex12DB", prop);
  }

  public ResultSet singleRowSearch(String tableName, String[] columnNameArray, String condition)
      throws SQLException {
    Statement st = con.createStatement();
    String sqls = "SELECT " + columnNameArray[0];
    for (int i = 1; i < columnNameArray.length; i++) {
      sqls = sqls + "," + columnNameArray[i];
    }
    sqls = sqls + " FROM " + tableName + " WHERE " + condition;
    //System.out.println(sqls);
    return st.executeQuery(sqls);
  }

  public boolean singleRowInsert(String tableName, String[] columnNameArray,
      String[] columnValuesArray) throws SQLException {
    Statement st = con.createStatement();
    String sqls = "INSERT INTO " + tableName + "(" + columnNameArray[0];
    for (int i = 1; i < columnNameArray.length; i++) {
      sqls = sqls + "," + columnNameArray[i];
    }
    sqls = sqls + ") VALUES( " + columnValuesArray[0];
    for (int i = 1; i < columnValuesArray.length; i++) {
      sqls = sqls + "," + columnValuesArray[i];
    }
    sqls = sqls + ")";
    //System.out.println(sqls);
    st.executeUpdate(sqls);
    return true;
  }

  /* This method is not used for this exercise !! */
  public boolean rowUpdate(String tableName, String[] columnNameArray, String[] columnValuesArray,
      String condition) throws SQLException {
    Statement st = con.createStatement();
    String sqls = "UPDATE " + tableName + " SET " + columnNameArray[0] + "=" + columnValuesArray[0];
    for (int i = 1; i < columnNameArray.length; i++) {
      sqls = sqls + "," + columnNameArray[i] + "=" + columnValuesArray[i];
    }
    sqls = sqls + " WHERE " + condition;
    //System.out.println(sqls);
    st.executeUpdate(sqls);
    return true;
  }
}
