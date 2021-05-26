package se1ex12.src;
/*
 * University of Aizu [Introduction to Software Engineering] Exercise material
 *
 * Class: Procurement
 *
 * Date: 2018/07/01
 *
 * author: University of Aizu & Nihon Unisys, Ltd. Technical Research Institute
 * 
 * This code may be used without modification
 */

// Implementation for Procurement class

import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Procurement {
  public static final String STATUS_ORDERED = "Ordered";
  public static final String STATUS_DELIVERED = "Delivered";
  public static final String STATUS_UNPAID = "Payment Requested";
  public static final String STATUS_PAID = "Payment Completed";

  private String procurementId;
  private String staffCode;
  private String materialCode;
  private Integer amount;
  private Date requestedDate;
  private Date deliveryDate;
  private String procurementStatus;
  private String paymentId;
  private DBAccess dbAccess;

  public Procurement(String procurementId, String staffCode, String materialCode, Integer amount,
      Date requestedDate, DBAccess dbAccess) {
    this.procurementId = procurementId;
    this.staffCode = staffCode;
    this.materialCode = materialCode;
    this.amount = amount;
    this.requestedDate = requestedDate;
    // Set default value (one month after requestedDate) for deliveryDate.
    Calendar cal = Calendar.getInstance();
    cal.setTime(requestedDate);
    cal.add(Calendar.MONTH, 1);
    this.deliveryDate = cal.getTime();
    this.procurementStatus = STATUS_ORDERED;;
    this.dbAccess = dbAccess;
  }

  public Procurement(String procurementId, DBAccess dbAccess) {
    this.procurementId = procurementId;
    this.dbAccess = dbAccess;
  }

  public Procurement(String procurementStatus, String procurementId, DBAccess dbAccess) {
    this.procurementStatus = procurementStatus;
    this.procurementId = procurementId;
    this.dbAccess = dbAccess;
  }

  public String getProcurementStatus() {
    return procurementStatus;
  }

  public void setProcurementStatus(String procurementStatus) {
    this.procurementStatus = procurementStatus;
  }

  public void setDeliveryDate(Date deliveryDate) {
    this.deliveryDate = deliveryDate;
  }

  public void setPaymentId(String paymentId) {
    this.paymentId = paymentId;
  }

  public boolean addProcurement() {
    if (checkProcurement()) {
      return false;
    }
    String[] cols = new String[] {"PROCUREMENTID", "STAFFCODE", "MATERIALCODE", "AMOUNT",
        "REQUESTEDDATE", "DELIVERYDATE", "PROCUREMENTSTATUS", "PAYMENTID"};
    String[] vals = new String[] {"'" + this.procurementId + "'", "'" + this.staffCode + "'",
        "'" + this.materialCode + "'", Integer.toString(this.amount),
        "'" + MyCalendar.formatDate(this.requestedDate) + "'",
        "'" + MyCalendar.formatDate(this.deliveryDate) + "'",
        "'" + this.procurementStatus + "'", "'" + this.paymentId + "'"};
    boolean sts = false;
    try {
      dbAccess.singleRowInsert("PROCUREMENT", cols, vals);
      return true;
    } catch (SQLException ex) {
      ex.printStackTrace();
      return false;
    }
  }

  public boolean checkProcurement() {
    String[] args = new String[] {"PROCUREMENTID", "STAFFCODE", "MATERIALCODE", "AMOUNT",
        "REQUESTEDDATE", "DELIVERYDATE", "PROCUREMENTSTATUS", "PAYMENTID"};
    boolean sts = false;
    try {
      ResultSet rs = dbAccess.singleRowSearch("PROCUREMENT", args,
          "PROCUREMENTID='" + this.procurementId + "'");

      while (rs.next()) {
        this.procurementId = rs.getString("PROCUREMENTID");
        this.staffCode = rs.getString("STAFFCODE");
        this.materialCode = rs.getString("MATERIALCODE");
        this.amount = rs.getInt("AMOUNT");
        this.requestedDate = rs.getDate("REQUESTEDDATE");
        this.deliveryDate = rs.getDate("DELIVERYDATE");
        this.procurementStatus = rs.getString("PROCUREMENTSTATUS");
        this.paymentId = rs.getString("PAYMENTID");
        sts = true;
      }
      return sts;
    } catch (SQLException ex) {
      ex.printStackTrace();
      return false;
    }
  }

  public boolean setDeliveryCompleted() {
    if (procurementStatus.equals(STATUS_ORDERED)) {
      procurementStatus = STATUS_DELIVERED;
      return true;
    } else {
      return false;
    }
  }

  public boolean setPaymentRequested() {
    if (procurementStatus.equals(STATUS_DELIVERED)) {
      procurementStatus = STATUS_UNPAID;
      return true;
    } else {
      return false;
    }
  }

  public boolean setPaymentCompleted() {
    if (procurementStatus.equals(STATUS_UNPAID)) {
      procurementStatus = STATUS_PAID;
      return true;
    } else {
      return false;
    }
  }
}
