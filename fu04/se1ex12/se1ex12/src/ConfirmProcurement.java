package se1ex12.src;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;
import java.util.StringTokenizer;

/*
 * University of Aizu [Introduction to Software Engineering] Exercise material
 *
 * Class: ConfirmProcurement
 *
 * Date: 2018/07/01
 *
 * author: University of Aizu & Nihon Unisys, Ltd. Technical Research Institute
 *
 * This class may be used without modification
 */

public class ConfirmProcurement {

  Connection con;

  public static void main(String[] args) {
    System.out.println("Confirm Procurement");
    ConfirmProcurement obj = new ConfirmProcurement();

    try {
      obj.connectDB();
      obj.readProcurementTable();
    } catch (SQLException e) {
      e.printStackTrace();
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    } finally {
      obj.disconnectDB();
    }
  }


  private void connectDB() throws SQLException, ClassNotFoundException {
    Class.forName("org.apache.derby.jdbc.EmbeddedDriver");

    Properties prop = new Properties();
    prop.put("create", "true"); 

    con = DriverManager.getConnection("jdbc:derby:SE1ex12DB", prop);
  }


  private void readProcurementTable() throws SQLException {
    Statement st = con.createStatement();
    ResultSet res = st.executeQuery("SELECT * FROM PROCUREMENT");
    while (res.next()) {
      System.out.println(
          "ProcurementID : " + res.getString("procurementId") + 
          " / StaffCode : " + res.getString("staffCode") +
          " / MaterialCode : " + res.getString("materialCode") +
          " / Amount : " + res.getString("amount") +
          " / ReauestedDate : " + res.getString("requestedDate") +
          " / Status : " + res.getString("procurementStatus") 
      );
    }
    try {
      res.close();
    } catch (SQLException e) {
    }
    try {
      st.close();
    } catch (SQLException e) {
    }
  }


  private void disconnectDB() {
    if (con != null) {
      try {
        con.close();
      } catch (SQLException e) {
        e.printStackTrace();
      }
      con = null;

      try {
        DriverManager.getConnection("jdbc:derby:;shutdown=true");
      } catch (SQLException e) {
        // When Disconnect succeeds,  confirm it because an exception called XJ015 is emitted.
        if (e.getSQLState().equals("XJ015")) {
        } else {
          // Exception normal other than XJ015
          e.printStackTrace();
        }
      }
    }
  }
}
