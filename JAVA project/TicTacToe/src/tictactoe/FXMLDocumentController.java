
package tictactoe;

import javafx.scene.control.Label;
import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.fxml.FXML;
import javafx.scene.layout.GridPane;
import javafx.scene.control.MenuItem;
import javafx.collections.ObservableList;
import javafx.scene.Node;

/**
 *                                          Tic Tac Toe Project
 * 
 *                                       Created by Wasy and Tanmim    
 * 
 */
public class FXMLDocumentController {
    
   @FXML Button b1; 
   @FXML Button b2;
   @FXML Button b3;
   @FXML Button b4;
   @FXML Button b5;
   @FXML Button b6;
   @FXML Button b7;
   @FXML Button b8;
   @FXML Button b9;   
   @FXML GridPane gameBoard;
   @FXML Label lbl;

   private boolean isFirstPlayer = true;
   private  String first;
   private String second;
   private String win;
   private String winningPlayer;
   
   
   public void buttonClickHandler(ActionEvent evt){
       
        Button clickedButton = (Button) evt.getTarget();
        first = "First Player's Turn (' X ') ";
        second = "Second player's Turn (' O ')";
        
        
        String buttonLabel = clickedButton.getText();
        
        
        if ("".equals(buttonLabel) && isFirstPlayer){

            clickedButton.setText("X");
        //labelString = "First Player";
        lbl.setText(second);
            isFirstPlayer = false;

        } else if("".equals(buttonLabel) && !isFirstPlayer){

            clickedButton.setText("O");
            
            lbl.setText(first);

            isFirstPlayer = true;

        }
        //System.out.println(find3InARow());
        
        find3InARow();
        

   }        
   private boolean find3InARow(){

       //Row 1

       if (!b1.getText().equals("")  && b1.getText().equals(b2.getText()) && b2.getText().equals(b3.getText())){
           
           highlightWinningCombo(b1,b2,b3);
          

           return true;

       }

       //Row 2

       if (!b4.getText().equals("") && b4.getText().equals(b5.getText()) && b5.getText().equals(b6.getText())){

           highlightWinningCombo(b4,b5,b6);
          
           return true;

       }

       //Row 3

       if (!b7.getText().equals("") && b7.getText().equals(b8.getText()) && b8.getText().equals(b9.getText())){

           highlightWinningCombo(b7,b8,b9);
       
           return true;

       }

       //Column 1

       if (!b1.getText().equals("") && b1.getText().equals(b4.getText()) && b4.getText().equals(b7.getText())){

           highlightWinningCombo(b1,b4,b7);
           
           return true;

       }

       //Column 2

       if (!b2.getText().equals("") && b2.getText().equals(b5.getText()) && b5.getText().equals(b8.getText())){

           highlightWinningCombo(b2,b5,b8);
           
           return true;

       }

       //Column 3

       if (!b3.getText().equals("") && b3.getText().equals(b6.getText()) && b6.getText().equals(b9.getText())){

           highlightWinningCombo(b3,b6,b9);
           
           return true;

       }

       //Diagonal 1

       if (!b1.getText().equals("") && b1.getText().equals(b5.getText()) && b5.getText().equals(b9.getText()) ){

           highlightWinningCombo(b1,b5,b9);
           
           return true;

     }

       //Diagonal 2

       
	   
       if (!"".equals(b3.getText()) && (b3.getText() == null ? b5.getText() == null : b3.getText().equals(b5.getText())) 

           && (b5.getText() == null ? b7.getText() == null : b5.getText().equals(b7.getText()))){
               highlightWinningCombo(b3,b5,b7);
               
               return true;
           } 
       if(!"".equals(b1.getText())&&!"".equals(b2.getText())&&!"".equals(b3.getText())&&!"".equals(b4.getText())&&!"".equals(b5.getText())&&!"".equals(b6.getText())&&!"".equals(b7.getText())&&!"".equals(b8.getText())&&!"".equals(b9.getText()))
       {
           lbl.setText("Draw, Play Again");
       }
           return false;

   }
   private void freezeGame()
   {
       b1.setDisable(true);
       b2.setDisable(true);
       b3.setDisable(true);
       b4.setDisable(true);
       b5.setDisable(true);
       b6.setDisable(true);
       b7.setDisable(true);
       b8.setDisable(true);
       b9.setDisable(true);
       
   }
    private void startGame()
   {
       b1.setDisable(false);
       b2.setDisable(false);
       b3.setDisable(false);
       b4.setDisable(false);
       b5.setDisable(false);
       b6.setDisable(false);
       b7.setDisable(false);
       b8.setDisable(false);
       b9.setDisable(false);
       
   }
   
private void highlightWinningCombo(Button first, Button second, Button third){
 first.setStyle("-fx-background-color:orangered ; -fx-border-width: 5px; -fx-border-color:RoyalBlue ; -fx-font-size:40px;");
 second.setStyle("-fx-background-color:orangered ; -fx-border-width: 5px; -fx-border-color:RoyalBlue ;-fx-font-size:40px;");
 third.setStyle("-fx-background-color:orangered ; -fx-border-width: 5px; -fx-border-color:RoyalBlue ;-fx-font-size:40px;");
 if(first.getText().equals("X"))lbl.setText("First Player Wins!!!");
 else if(first.getText().equals("O"))lbl.setText("Second Player Wins!!!");
 
 freezeGame();

}
   @FXML
 public void menuClickHandler(ActionEvent evt){

        MenuItem clickedMenu = (MenuItem) evt.getTarget();

        String menuLabel = clickedMenu.getText();

        if ("Again Play".equals(menuLabel)){

            ObservableList<Node> buttons = gameBoard.getChildren();

            buttons.forEach(btn -> {
                
                ((Button) btn).setText("");
                
                                                                 //  this is set color after click new game 
                                                                 
                 ((Button) btn).setStyle("-fx-background-color:#19356c ; -fx-border-width: 5px; -fx-border-color:#3667c9;-fx-font-size:40px;");

                //btn.getStyleClass().remove("winning-button");

            });
            
            startGame();
            lbl.setText(first);

            isFirstPlayer = true;          // new game starts with X

        }
   
  

   }
   
 
 


}

