<?php
class Asset{
    private $_assetId;
    private $_assetTypeId;
    private $_assetSerialNo;
    private $_assetModelNo;
    private $_assetBrand;
    private $_assetPurchaseDate;
    private $_assetStatus;
    private $_assetConfiguration;
    private $_assetStuffId;
    private $_assetPurchasedFrom;
    private $_assetCost;
    private $_assetWarrantyLimit;
    
    //Id
    public function getAssetId(){
        return $this->_assetId;
    }
    
    public function setAssetId($assetId){
        $this->_assetId=$assetId;
    }
    
    //TypeId
    public function getAssetTypeId(){
        return $this->_assetTypeId;
    }
    
    public function setAssetTypeId($assetTypeId){
        $this->_assetTypeId=$assetTypeId;
    }
    
    //Serial No
    public function getAssetSerialNo(){
        return $this->_assetSerialNo;
    }
    
    public function setAssetSerialNo($assetSerialNo){
        $this->_assetSerialNo=$assetSerialNo;
    }
    
    //Model No
    public function getAssetModelNo(){
        return $this->_assetModelNo;
    }
    
    public function setAssetModelNo($assetModelNo){
        $this->_assetModelNo=$assetModelNo;
    }
    
    //Brand
    public function getAssetBrand(){
        return $this->_assetBrand;
    }
    
    public function setAssetBrand($assetBrand){
        $this->_assetBrand=$assetBrand;
    }
    
    //PurchaseDate
    public function getAssetPurchaseDate(){
        return $this->_assetPurchaseDate;
    }
    
    public function setAssetPurchaseDate($assetPurchaseDate){
        $this->_assetPurchaseDate=$assetPurchaseDate;
    }

    //Status
    public function getAssetStatus(){
        return $this->_assetStatus;
    }

    public function setAssetStatus($assetStatus){
        $this->_assetStatus=$assetStatus;
    }

    //Configuration
    public function getAssetConfiguration(){
        return $this->_assetConfiguration;
    }

    public function setAssetConfiguration($assetConfiguration){
        $this->_assetConfiguration=$assetConfiguration;
    }
    
    //Stuff
    public function getAssetStuffId(){
        return $this->_assetStuffId;
    }
    
    public function setAssetStuffId($assetStuffId){
        $this->_assetStuffId=$assetStuffId;
    }
    
    
    //Purchased From
    public function getAssetPurchasedFrom(){
        return $this->_assetPurchasedFrom;
    }

    public function setAssetPurchasedFrom($assetPurchasedFrom){
        $this->_assetPurchasedFrom=$assetPurchasedFrom;
    }
    
    //Cost
    public function getAssetCost(){
        return $this->_assetCost;
    }
    
    public function setAssetCost($assetCost){
        $this->_assetCost=$assetCost;
    }

    //Warranty
    public function getAssetWarrantyLimit(){
        return $this->_assetWarrantyLimit;
    }
    
    public function setAssetWarrantyLimit($assetWarrantyLimit){
        $this->_assetWarrantyLimit=$assetWarrantyLimit;
    }
    

}

class AssetType{
    private $_assetTypeId;
    private $_assetTypeName;

    //Id
    public function getAssetTypeId(){
        return $this->_assetTypeId;
    }

    public function setAssetTypeId($assetTypeId){
        $this->_assetTypeId=$assetTypeId;
    }

    //Name
    public function getAssetTypeName(){
        return $this->_assetTypeName;
    }

    public function setAssetTypeName($assetTypeName){
        $this->_assetTypeName=$assetTypeName;
    }


}

class Repair{
    private $_repairId;
    private $_repairAssetId;
    private $_repairProblem;
    private $_repairSendingDate;
    private $_repairReceivingDate;
    private $_repairStatus;
    private $_repairSentBy;
    private $_repairReceivedBy;
    private $_repairRepairedFrom;
    private $_repairCost;
    private $_repairOnWarranty;
    private $_repairIsReceived;

    //Id
    public function getRepairId(){
        return $this->_repairId;
    }

    public function setRepairId($repairId){
        $this->_repairId=$repairId;
    }

    //AssetId
    public function getRepairAssetId(){
        return $this->_repairAssetId;
    }

    public function setRepairAssetId($repairAssetId){
        $this->_repairAssetId=$repairAssetId;
    }

    //Problem
    public function getRepairProblem(){
        return $this->_repairProblem;
    }

    public function setRepairProblem($repairProblem){
        $this->_repairProblem=$repairProblem;
    }

    //Sending Date
    public function getRepairSendingDate(){
        return $this->_repairSendingDate;
    }

    public function setRepairSendingDate($repairSendingDate){
        $this->_repairSendingDate=$repairSendingDate;
    }

    //Receiving Date
    public function getRepairReceivingDate(){
        return $this->_repairReceivingDate;
    }

    public function setRepairReceivingDate($repairReceivingDate){
        $this->_repairReceivingDate=$repairReceivingDate;
    }

    //Status
    public function getRepairStatus(){
        return $this->_repairStatus;
    }

    public function setRepairStatus($repairStatus){
        $this->_repairStatus=$repairStatus;
    }

    //Sent By
    public function getRepairSentBy(){
        return $this->_repairSentBy;
    }

    public function setRepairSentBy($repairSentBy){
        $this->_repairSentBy=$repairSentBy;
    }
    
    //Received By
    public function getRepairReceivedBy(){
        return $this->_repairReceivedBy;
    }
    
    public function setRepairReceivedBy($repairReceivedBy){
        $this->_repairReceivedBy=$repairReceivedBy;
    }
    
    //Repaired From
    public function getRepairRepairedFrom(){
        return $this->_repairRepairedFrom;
    }
    
    public function setRepairRepairedFrom($repairRepairedFrom){
        $this->_repairRepairedFrom=$repairRepairedFrom;
    }
    
    //Cost
    public function getRepairCost(){
        return $this->_repairCost;
    }
    
    public function setRepairCost($repairCost){
        $this->_repairCost=$repairCost;
    }
    
    //OnWarranty
    public function getRepairOnWarranty(){
        return $this->_repairOnWarranty;
    }
    
    public function setRepairOnWarranty($repairOnWarranty){
        $this->_repairOnWarranty=$repairOnWarranty;
    }
    
    //IsReceived
    public function getRepairIsReceived(){
        return $this->_repairIsReceived;
    }
    
    public function setRepairIsReceived($repairIsReceived){
        $this->_repairIsReceived=$repairIsReceived;
    }
}

class UserAsset{
    private $_UserAssetId;
    private $_UserAssetUserId;
    private $_UserAssetAssetId;
    private $_UserAssetLendingDate;

    //Id
    public function getUserAssetId(){
        return $this->_UserAssetId;
    }

    public function setUserAssetId($UserAssetId){
        $this->_UserAssetId=$UserAssetId;
    }

    //User Id
    public function getUserAssetUserId(){
        return $this->_UserAssetUserId;
    }

    public function setUserAssetUserId($UserAssetUserId){
        $this->_UserAssetUserId=$UserAssetUserId;
    }

    //Asset Id
    public function getUserAssetAssetId(){
        return $this->_UserAssetAssetId;
    }

    public function setUserAssetAssetId($UserAssetAssetId){
        $this->_UserAssetAssetId=$UserAssetAssetId;
    }
    
    //Date
    public function getUserAssetLendingDate(){
        return $this->_UserAssetLendingDate;
    }
    
    public function setUserAssetLendingDate($UserAssetLendingDate){
        $this->_UserAssetLendingDate=$UserAssetLendingDate;
    }
    
}
?>