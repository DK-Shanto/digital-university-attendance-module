<?php
// write dao object for each class
include_once COMMON.'class.common.asset.inc';
include_once UTILITY.'class.util.inc';

Class AssetDetailsDao
{

    private $_DB;
    private $_Asset;
    private $_Repair;

    function __construct()
    {
        $this->_DB = DBUtil::getInstance();
        $this->_Asset = new Asset();
        $this->_Repair=new Repair();
    }

    public function getAsset($Asset){
        $SQL="SELECT * FROM ams_asset WHERE ams_asset.serialNo='".$Asset->getAssetSerialNo()."'";
        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow();

        $this->_Asset=new Asset();
        $this->_Asset->setAssetId($row['id']);
        $this->_Asset->setAssetTypeId($row['type_id']);
        $this->_Asset->setAssetSerialNo($row['serialNo']);
        $this->_Asset->setAssetModelNo($row['modelNo']);
        $this->_Asset->setAssetBrand($row['brand']);
        $this->_Asset->setAssetPurchaseDate($row['purchaseDate']);
        $this->_Asset->setAssetStatus($row['status']);
        $this->_Asset->setAssetConfiguration($row['configuration']);
        $this->_Asset->setAssetStuffId($row['stuff_id']);
        $this->_Asset->setAssetPurchasedFrom($row['purchasedFrom']);
        $this->_Asset->setAssetCost($row['cost']);
        $this->_Asset->setAssetWarrantyLimit($row['warrantyLimit']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Asset);

        return $Result;
    }

    public function getRepairByAssetId($Asset){
        $RepairList=array();
        $SQL="SELECT * FROM ams_repair WHERE ams_repair.asset_id='$Asset'";

        $this->_DB->doQuery($SQL);
        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row){
            $this->_Repair=new Repair();
            $this->_Repair->setRepairId($row['id']);
            $this->_Repair->setRepairAssetId($row['asset_id']);
            $this->_Repair->setRepairProblem($row['problem']);
            $this->_Repair->setRepairSendingDate($row['sendingDate']);
            $this->_Repair->setRepairReceivingDate($row['receivingDate']);
            $this->_Repair->setRepairStatus($row['status']);
            $this->_Repair->setRepairSentBy($row['sent_by']);
            $this->_Repair->setRepairReceivedBy($row['received_by']);
            $this->_Repair->setRepairRepairedFrom($row['repaired_from']);
            $this->_Repair->setRepairCost($row['cost']);
            $this->_Repair->setRepairOnWarranty($row['onWarranty']);

            $RepairList[]=$this->_Repair;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($RepairList);

        return $Result;
    }

    public function deleteRepair($Repair){
        $SQL="DELETE FROM ams_repair WHERE ams_repair.id='$Repair'";
        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }
}