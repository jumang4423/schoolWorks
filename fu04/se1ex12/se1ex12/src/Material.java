package se1ex12.src;

import java.sql.ResultSet;
import java.sql.SQLException;

/*
 * University of Aizu [Introduction to Software Engineering] Exercise material
 *
 * Class: Material
 *
 * Date: 2018/07/01
 *
 * author: University of Aizu & Nihon Unisys, Ltd. Technical Research Institute
 * 
 * This code may be used without modification
 */



public class Material {
  private String materialCode;
  private String name;
  private DBAccess dbAccess;

  public Material(String materialCode, DBAccess dbAccess) {
    this.materialCode = materialCode;
    this.dbAccess = dbAccess;
  }

  public String getName() {
    return name;
  }

  public boolean checkMaterial() {
    String[] args = new String[] {"MATERIALCODE", "NAME"};
    boolean sts = false;
    try {
      ResultSet rs =
          dbAccess.singleRowSearch("MATERIAL", args, "MATERIALCODE='" + materialCode + "'");

      while (rs.next()) {
        this.materialCode = rs.getString("materialCode");
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
