package se1ex12.src;

/*
 * University of Aizu [Introduction to Software Engineering] Exercise material
 *
 * Class: ProcurementControl
 *
 * Date: 2021/05/26
 *
 * author: Ryoma Okuda
 *
 */
/*
 *
 * Complete the implementation of this class "ProcurementControl"
 *
 */
import java.sql.SQLException;
import java.util.Date;

public class ProcurementControl {
  // Declare necessary variables
  // private Procurement procurement;
  private DBAccess dbAccess;

  public ProcurementControl() throws ClassNotFoundException, SQLException {
    // Initialization of DBAccess
    dbAccess = new DBAccess();
  }

  // Declare and implement necessary methods

  // return one ProcurementStaff object
  // - null for non staff
  public ProcurementStaff getProcurementStaff(String _staffCode) {
    // new instance
    ProcurementStaff procurementStaff = new ProcurementStaff(_staffCode, this.dbAccess);

    return procurementStaff.checkStaff() ? procurementStaff : null;
  }

  // return one Material object
  // - null for non staff
  public Material getMaterial(String _materialCode) {
    // new instance
    Material material = new Material(_materialCode, this.dbAccess);

    return material.checkMaterial() ? material : null;
  }

  // return one Procurement object
  // - null for non staff
  public Procurement getProcurement(String _procurementId) {
    // new instance
    Procurement procurement = new Procurement(_procurementId, this.dbAccess);

    return procurement.checkProcurement() ? procurement : null;
  }

  // return boolean that added procurement exists or not
  // - null for non procurement
  public Boolean recordProcurement(String _procurementId, String _staffCode, String _materialCode, Integer _amount,
      Date _requestedDate) {
    Procurement procurement = new Procurement(_procurementId, _staffCode, _materialCode, _amount, _requestedDate,
        this.dbAccess);
    return procurement.addProcurement();
  }

  // return boolean that setDeliveryCompleted() result
  // - null for non procurement
  public boolean recordDelivery(String _procurementId, Date _deliveryDate) {
    Procurement procurement = new Procurement(_procurementId, this.dbAccess);

    if (procurement.checkProcurement()) {
      procurement.setDeliveryDate(_deliveryDate);
      return procurement.setDeliveryCompleted();
    } else {
      return false;
    }
  }

}
