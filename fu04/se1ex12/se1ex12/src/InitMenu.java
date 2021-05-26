package se1ex12.src;

/*
 * University of Aizu [Introduction to Software Engineering] Exercise material
 *
 * Class: InitMenu
 *
 * Date: 2017/05/04
 *
 * author: University of Aizu & Nihon Unisys, Ltd. Technical Research Institute
 * 
 * This code may be used without modification
 */

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.WindowConstants;

public class InitMenu implements ActionListener {
  private static final String ACTION_OPEN_PANEL = "Open Record Procurement Panel";

  public InitMenu() {
    JButton recordPurchaseButton = new JButton("Open Record Procurement Panel");
    recordPurchaseButton.setActionCommand(ACTION_OPEN_PANEL);
    recordPurchaseButton.addActionListener(this);

    JButton exitButton = new JButton("Exit");
    exitButton.addActionListener(this);

    JPanel pnlButton = new JPanel();
    pnlButton.setLayout(new GridLayout(2, 1, 5, 5));
    pnlButton.add(recordPurchaseButton);
    pnlButton.add(exitButton);

    JFrame frame = new JFrame("Operation Selection Panel");
    frame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    frame.setLayout(new BorderLayout());
    frame.getContentPane().add(pnlButton, "Center");

    frame.setSize(400, 200);
    frame.setVisible(true);
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getActionCommand().equals(ACTION_OPEN_PANEL)) {
      RecordProcurementPanel recordProcurementPanel = new RecordProcurementPanel();
    } else {
      // Exit button clicked.
      System.exit(0);
    }
  }

  public static void main(String[] args) {
    InitMenu initMenu = new InitMenu();
  }
}
