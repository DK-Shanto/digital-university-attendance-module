<?php
include_once 'blade/view.assetDetails.blade.inc';
include_once COMMON.'class.common.inc';
?>

<div class="container">
    <div class="col-md-8 col-md-offset-2">
        <div class="panel panel-default myPanel">
            <div class="panel-heading myHeading" style="margin-bottom: 0vh">
                <strong><img src="./resources/img/assetDetails.png" alt="Icon" class="myImg">&nbsp;Asset Details</strong>
            </div>
            <div class="panel-body">
                <div class="form-horizontal">
                    <?php
                    $Asset->setAssetSerialNo($_GET['serialNo']);
                    $Result=$_AssetDetailsBao->getAsset($Asset)->getResultObject();
                    ?>
                    <!--Hidden Id-->
                    <div class="form-group">
                        <div class=" col-md-7">
                            <input type="hidden" name="aid" id="aid" class="form-control" value="<?php
                            echo $Result->getAssetId(); ?>">
                        </div>
                    </div>

                    <!--Type-->
                    <div class="form-group">
                        <label for="type" class="control-label col-md-4">Type :</label>
                        <div id="type" class="control-label col-md-7 text-justify">
                            <?php
                            echo $_AssetBao->getTypeById($Result->getAssetTypeId())->getResultObject()->getAssetTypeName();
                            ?>
                        </div>
                    </div>

                    <!--Serial No-->
                    <div class="form-group">
                        <label for="serialNo" class="control-label col-md-4">Serial No :</label>
                        <div id="serialNo" class="control-label col-md-7 text-justify">
                            <?php
                            echo $Result->getAssetSerialNo();
                            ?>
                        </div>
                    </div>

                    <!--Model No-->
                    <div class="form-group">
                        <label for="modelNo" class="control-label col-md-4">Model No :</label>
                        <div id="modelNo" class="control-label col-md-7 text-justify">
                            <?php
                            echo $Result->getAssetModelNo();
                            ?>
                        </div>
                    </div>

                    <!--Brand-->
                    <div class="form-group">
                        <label for="brand" class="control-label col-md-4">Brand :</label>
                        <div id="brand" class="control-label col-md-7 text-justify">
                            <?php
                            echo $Result->getAssetBrand();
                            ?>
                        </div>
                    </div>

                    <!--Purchase Date-->
                    <div class="form-group">
                        <label for="purchaseDate" class="control-label col-md-4">Purchase Date :</label>
                        <div id="purchaseDate" class="control-label col-md-7 text-justify">
                            <?php
                            echo date_format(new DateTime($Result->getAssetPurchaseDate()),"d-M-Y");
                            ?>
                        </div>
                    </div>

                    <!--Status-->
                    <div class="form-group">
                        <label for="status" class="control-label col-md-4">Current Status :</label>
                        <div id="status" class="control-label col-md-7 text-justify <?php if ($Result->getAssetStatus()=="Working"){
                            echo 'text-success';
                        }elseif ($Result->getAssetStatus()=="On Repair"){
                            echo 'text-warning';
                        }else{
                            echo 'text-danger';
                        } ?>">
                            <?php
                            echo $Result->getAssetStatus();
                            ?>
                        </div>
                    </div>

                    <!--Short Configuration-->
                    <div id="shortConfiguration" class="form-group">
                        <label for="configuration" class="control-label col-md-4">Configuration :</label>
                        <div id="configuration" class=" control-label col-md-7 text-justify">
                            <?php
                            if(strlen($Result->getAssetConfiguration())>250){
                                echo substr($Result->getAssetConfiguration(),0,250).'...'.'<a href="#" onclick="rmFunction();">Read more</a>';
                            }
                            else{
                                echo $Result->getAssetConfiguration();
                            }
                            ?>
                        </div>
                    </div>

                    <!--Long Configuration-->
                    <div id="longConfiguration" class="form-group" style="display: none">
                        <label for="configuration" class="control-label col-md-4">Configuration :</label>
                        <div id="configuration" class=" control-label col-md-7 text-justify">
                            <?php
                            echo $Result->getAssetConfiguration();
                            ?>
                        </div>
                    </div>

                    <!--Received By-->
                    <div class="form-group">
                        <label for="receivedBy" class="control-label col-md-4">Received By :</label>
                        <div id="receivedBy" class="control-label col-md-7 text-justify">
                            <?php
                            $Name=$_AssetBao->getStuffById($Result->getAssetStuffId())->getResultObject();
                            echo $Name->getFirstName().' '.$Name->getLastName();
                            ?>
                        </div>
                    </div>

                    <!--Purchased From-->
                    <div class="form-group">
                        <label for="purchasedFrom" class="control-label col-md-4">Purchased From :</label>
                        <div id="purchasedFrom" class="control-label col-md-7 text-justify">
                            <?php
                            echo $Result->getAssetPurchasedFrom();
                            ?>
                        </div>
                    </div>

                    <!--Price-->
                    <div class="form-group">
                        <label for="price" class="control-label col-md-4">Price :</label>
                        <div id="price" class="control-label col-md-7 text-justify">
                            <?php
                            echo $Result->getAssetCost();
                            ?>
                        </div>
                    </div>

                    <!--Warranty Limit-->
                    <div class="form-group">
                        <label for="warrantyLimit" class="control-label col-md-4">Warranty Limit :</label>
                        <div id="warrantyLimit" class="control-label col-md-7 text-justify">
                            <?php
                            echo date_format(new DateTime($Result->getAssetWarrantyLimit()),"d-M-Y");
                            ?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
<!--Display all member(s)-->
<div class="col-md-12">
    <hr>
</div>
<div class="col-md-12">
    <div class="panel panel-table">
        <table class="table table-bordered table-responsive">
            <!--Header Row-->
            <tr>
                <th>Problem</th>
                <th>Sent By</th>
                <th>Received By</th>
                <th>Sending Date</th>
                <th>Receiving Date</th>
                <th>Repair Status</th>
                <th>Repaired From</th>
                <th>Cost</th>
                <th>On Warranty</th>
                <th><img src="./resources/img/delete.png" alt="Delete" class="table-img"></th>
            </tr>

            <!--Table Cells-->
            <?php
            $Result2=$_AssetDetailsBao->getRepairByAssetId($Result->getAssetId());
            if($Result2->getIsSuccess()) {
                $RepairList = $Result2->getResultObject();
                foreach ($RepairList as $repair) {
                    ?>
                    <tr <?php if ($repair->getRepairStatus()=="Repaired"){
                        echo 'class="table-cell alert-success"';
                    }elseif ($repair->getRepairStatus()=="Partially Repaired"){
                        echo 'class="table-cell alert-warning"';
                    }elseif($repair->getRepairStatus()=="Not Repaired"){
                        echo 'class="table-cell alert-danger"';
                    }else{
                        echo 'class="table-cell"';
                    }
                    ?>>
                        <td>
                            <?php
                                echo $repair->getRepairProblem();
                            ?>
                        </td>

                        <?php
                        $StuffName=$_AssetBao->getStuffById($repair->getRepairSentBy())->getResultObject();
                        ?>
                        <td><a href="user_details.php?id=<?php echo $StuffName->getID(); ?>" style="text-decoration: none" class="table-a"><?php
                                echo $StuffName->getFirstName().' '.$StuffName->getLastName();
                                ?></a>
                        </td>

                        <?php
                        $StuffName=$_AssetBao->getStuffById($repair->getRepairReceivedBy())->getResultObject();
                        ?>
                        <td>
                            <?php
                            if (!empty($StuffName->getID())){
                                ?>
                                <a href="user_details.php?id=<?php echo $StuffName->getID(); ?>" style="text-decoration: none" class="table-a"><?php
                                    echo $StuffName->getFirstName().' '.$StuffName->getLastName();
                                    ?></a>
                                <?php
                            }else{
                                echo '---';
                            }
                            ?>
                        </td>

                        <td>
                            <?php echo $repair->getRepairSendingDate(); ?>
                        </td>
                        <td>
                            <?php
                            if (!empty($repair->getRepairReceivingDate())){
                                echo $repair->getRepairReceivingDate();
                            }else{
                                echo '---';
                            }
                             ?>
                        </td>
                        <td>
                            <?php if (!empty($repair->getRepairStatus())){
                                echo $repair->getRepairStatus();
                            }else{
                                echo '---';
                            }
                             ?>
                        </td>
                        <td>
                            <?php echo $repair->getRepairRepairedFrom(); ?>
                        </td>
                        <td>
                            <?php if ($repair->getRepairOnWarranty()){
                                echo "---";
                            }else{
                                if (!empty($repair->getRepairCost())){
                                    echo $repair->getRepairCost();
                                }else{
                                    echo '---';
                                }
                            }
                            ?>
                        </td>
                        <td <?php if ($repair->getRepairOnWarranty()){
                            echo 'class="text-success"';
                        }else{
                            echo 'class="text-danger"';
                        }
                        ?>>
                            <?php if ($repair->getRepairOnWarranty()){
                                echo 'Yes';
                            }else{
                                echo 'No';
                            } ?>
                        </td>
                        <td><a href="?serialNo=<?php echo $_GET['serialNo']; ?>&del=<?php echo $repair->getRepairId(); ?>"
                               class="span-danger"
                               onclick="return confirm('sure to delete !!');">delete</a></td>
                    </tr>
                    <?php
                }
            }
            ?>
        </table>
    </div>
</div>

<!--Script for searching and adding members-->
<script>
    function rmFunction() {
        $('#shortConfiguration').hide();
        $('#longConfiguration').show();
    }
</script>