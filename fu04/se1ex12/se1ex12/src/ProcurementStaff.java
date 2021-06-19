package se1ex12.src;

import java.sql.ResultSet;
import java.sql.SQLException;

/*
 * University of Aizu [Introduction to Software Engineering] Exercise material
 *
 * Class: ProcurementStaff
 *
 * Date: 2018/07/01
 *
 * author: University of Aizu & Nihon Unisys, Ltd. Technical Research Institute
 * 
 * This code may be used without modification
 */

public class ProcurementStaff {
  private String staffCode;
  private String name;
  private DBAccess dbAccess;

  public ProcurementStaff(String staffCode, DBAccess dbAccess) {
    this.staffCode = staffCode;
    this.dbAccess = dbAccess;
  }

  public String getName() {
    return name;
  }

  public boolean checkStaff() {
    String[] args = new String[] {"STAFFCODE", "NAME"};
    boolean sts = false;
    try {
      ResultSet rs =
          dbAccess.singleRowSearch("PROCUREMENTSTAFF", args, "STAFFCODE='" + staffCode + "'");

      while (rs.next()) {
        this.staffCode = rs.getString("staffCode");
        this.name = rs.getString("name");
        sts = true;
      }
      return sts;
    } catch (SQLException ex) {
      ex.printStackTrace();
      return false;
    }
  }
}
