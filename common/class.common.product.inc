<?php

class ProductCategory{

    private $_ID;
    private $_Category;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setCategory( $Category ) {
        $this->_Category = $Category;
    }

    public function getCategory() {
        return $this->_Category;
    }

}


class Products{

    private $_ID;
    private $_Name;
    private $_CategoryID;
    private $_Price;
    private $_Offered_Credit;
    private $_Picture;


    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setName ( $Name ) {
        $this->_Name = $Name;
    }

    public function getName () {
        return $this->_Name;
    }

    public function setCategoryID( $CategoryID ) {
        $this->_CategoryID = $CategoryID;
    }

    public function getCategoryID() {
        return $this->_CategoryID;
    }

    public function setPrice ( $Price ) {
        $this->_Price = $Price;
    }

    public function getPrice () {
        return $this->_Price;
    }

    public function setOfferedCredit ( $OfferedCredit ) {
        $this->_Offered_Credit = $OfferedCredit;
    }

    public function getOfferedCredit () {
        return $this->_Offered_Credit;
    }
    public function setPicture($Picture){
        $this->_Picture = $Picture;
    }
    public function getPicture () {
        return $this->_Picture;
    }

}

class Cart{
    private $_ID;
    private $_ProductID;
    private $_UserID;
    private $_DateTime;

    public function setID ( $ID ) {
        $this->_ID = $ID;
    }

    public function getID () {
        return $this->_ID;
    }


    public function setProductID ( $ProductID ) {
        $this->_ProductID = $ProductID;
    }

    public function getProductID () {
        return $this->_ProductID;
    }

    public function setUserID( $UserID ) {
        $this->_UserID = $UserID;
    }

    public function getUserID() {
        return $this->_UserID;
    }

    public function setDateTime ( $DateTime ) {
        $this->_DateTime = $DateTime;
    }

    public function getDateTime () {
        return $this->_DateTime;
    }


}

class TotalPayCredit{
    private $_TotalToPay;
    private $_TotalCredit;

    public function setTotalToPay($TotalToPay){
        $this->_TotalToPay=$TotalToPay;
    }

    public function getTotalToPay(){
        return $this->_TotalToPay;
    }

    public function setTotalCredit($TotalCredit){
        $this->_TotalCredit=$TotalCredit;
    }

    public function getTotalCredit(){
        return $this->_TotalCredit;
    }
}








?>