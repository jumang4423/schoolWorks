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
 * Class: InitDB
 *
 * Date: 2018/07/01
 *
 * author: University of Aizu & Nihon Unisys, Ltd. Technical Research Institute
 *
 * This class may be used without modification
 */

public class InitDB {

  Connection con;

  public static void main(String[] args) {
    System.out.println("Init Database");
    InitDB obj = new InitDB();

    try {
      obj.connectDB();
      // Initialize Tables
      obj.insertMaterialRec();
      obj.insertProcurementStaffRec();
      obj.insertSupplierRec();
      obj.initProcurementTable();
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


  private void insertMaterialRec() throws SQLException {
    Statement st = con.createStatement();
    try {
      st.executeUpdate(
          "CREATE TABLE MATERIAL(materialCode varchar(100) not null primary key, name varchar(100))");
    } catch (SQLException e) {
	  // Truncate table, if Table had already created.
      st.executeUpdate("TRUNCATE TABLE MATERIAL");
    }
    try {
      FileReader fr = new FileReader("./Material.csv");
      BufferedReader br = new BufferedReader(fr);
      String line;
      StringTokenizer token;
      while ((line = br.readLine()) != null) {
        token = new StringTokenizer(line, ",");
        String materialCode = "";
        String name = "";
        boolean er = false;
        if (token.hasMoreTokens())
          materialCode = token.nextToken();
        else
          er = true;
        if (token.hasMoreTokens())
          name = token.nextToken();
        else
          er = true;
        if (!er)
          st.executeUpdate("INSERT INTO MATERIAL VALUES('" + materialCode + "' , '" + name + "')");
      }
      br.close();
    } catch (IOException ex) {
      ex.printStackTrace();
    }
    // Read and Display table.
    ResultSet res = st.executeQuery("SELECT * FROM MATERIAL");
    while (res.next()) {
      System.out.println(
          "MaterialCode : " + res.getString("materialCode") + " / Name : " + res.getString("name"));
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

  private void insertProcurementStaffRec() throws SQLException {
    Statement st = con.createStatement();
    try {
      st.executeUpdate(
          "CREATE TABLE PROCUREMENTSTAFF(staffCode varchar(100) not null primary key, name varchar(100))");
    } catch (SQLException e) {
      st.executeUpdate("TRUNCATE TABLE PROCUREMENTSTAFF");
    }
    try {
      FileReader fr = new FileReader("./ProcurementStaff.csv");
      BufferedReader br = new BufferedReader(fr);
      String line;
      StringTokenizer token;
      while ((line = br.readLine()) != null) {
        token = new StringTokenizer(line, ",");
        String staffCode = "";
        String name = "";
        boolean er = false;
        if (token.hasMoreTokens())
          staffCode = token.nextToken();
        else
          er = true;
        if (token.hasMoreTokens())
          name = token.nextToken();
        else
          er = true;
        if (!er)
          st.executeUpdate(
              "INSERT INTO PROCUREMENTSTAFF VALUES('" + staffCode + "' , '" + name + "')");
      }
      br.close();
    } catch (IOException ex) {
      ex.printStackTrace();
    }
    ResultSet res = st.executeQuery("SELECT * FROM PROCUREMENTSTAFF");
    while (res.next()) {
      System.out.println(
          "StaffCode : " + res.getString("staffCode") + " / Name : " + res.getString("name"));
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

  private void insertSupplierRec() throws SQLException {
    Statement st = con.createStatement();
    try {
      st.executeUpdate(
          "CREATE TABLE SUPPLIER(supplierCode varchar(100) not null primary key, name varchar(100))");
    } catch (SQLException e) {
      st.executeUpdate("TRUNCATE TABLE SUPPLIER");
    }
    try {
      FileReader fr = new FileReader("./Supplier.csv");
      BufferedReader br = new BufferedReader(fr);
      String line;
      StringTokenizer token;
      while ((line = br.readLine()) != null) {
        token = new StringTokenizer(line, ",");
        String supplierCode = "";
        String name = "";
        boolean er = false;
        if (token.hasMoreTokens())
          supplierCode = token.nextToken();
        else
          er = true;
        if (token.hasMoreTokens())
          name = token.nextToken();
        else
          er = true;
        if (!er)
          st.executeUpdate("INSERT INTO SUPPLIER VALUES('" + supplierCode + "' , '" + name + "')");
      }
      br.close();
    } catch (IOException ex) {
      ex.printStackTrace();
    }
    ResultSet res = st.executeQuery("SELECT * FROM SUPPLIER");
    while (res.next()) {
      System.out.println(
          "SupplierCode : " + res.getString("supplierCode") + " / Name : " + res.getString("name"));
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

  private void initProcurementTable() throws SQLException {
    Statement st = con.createStatement();
    try {
      st.executeUpdate("CREATE TABLE PROCUREMENT("
          + "procurementId varchar(50) not null primary key, staffCode varchar(50), materialCode varchar(50),"
          + "amount integer, requestedDate date, deliveryDate date,"
          + "procurementStatus varchar(50),  paymentId varchar(50))");
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
