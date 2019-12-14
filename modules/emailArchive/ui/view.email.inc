<?php
include_once 'blade/view.email.blade.inc';
include_once COMMON.'class.common.inc';
?>
<div class="container">
    <div class="col-md-8 col-md-offset-2">
    <!--Heading-->
    <div class="panel panel-default myPanel">
        <div class="panel-heading myHeading">
            <strong><img src="./resources/img/createproject.png" height="60" width="60" alt="Icon" class="myImg">&nbsp;Create Email Record</strong>
        </div>
        <div class="panel-body">

            <!--Project Creation Form-->
            <form method="post" class="form-horizontal" enctype="multipart/form-data">

                <!--            FirstName-->
                <div class="form-group">
                    <label for="firstName" class="control-label col-md-3">First Name :</label>
                    <div class=" col-md-7">
                        <input type="text" name="firstName" id="firstName" class="form-control" placeholder="First Name" value="<?php
                        if (isset($_GET['edit'])) echo $getRow->getEmailFirstName();
                        elseif (isset($_POST['create'])) echo $_POST['firstName'];
                        ?>" required>
                        <span class="span-danger"><?php if (isset($_POST['create'])&&empty($_POST['firstName'])) echo '*FirstName is required';?></span>
                    </div>
                </div>

                <!--            LastName-->
                <div class="form-group">
                    <label for="lastName" class="control-label col-md-3">Last Name :</label>
                    <div class=" col-md-7">
                        <input type="text" name="lastName" id="lastName" class="form-control" placeholder="Last Name" value="<?php
                        if (isset($_GET['edit'])) echo $getRow->getEmailLastName();
                        elseif (isset($_POST['create'])) echo $_POST['lastName'];
                        ?>" required>
                        <span class="span-danger"><?php if (isset($_POST['create'])&&empty($_POST['lastName'])) echo '*LastName is required';?></span>
                    </div>
                </div>

                <!--            Email-->
                <div class="form-group">
                    <label for="email" class="control-label col-md-3">Email :</label>
                    <div class=" col-md-7">
                        <input type="email" name="email" id="email" class="form-control" placeholder="Email" value="<?php
                        if (isset($_GET['edit'])) echo $getRow->getEmailEmail();
                        elseif (isset($_POST['create'])) echo $_POST['email'];
                        ?>" required>
                        <span class="span-danger"><?php if (isset($_POST['create'])&&empty($_POST['email'])) echo '*Email is required';?></span>
                    </div>
                </div>

                <!--            Contact-->
                <div class="form-group">
                    <label for="contact" class="control-label col-md-3">Contact :</label>
                    <div class=" col-md-7">
                        <input type="text" name="contact" id="contact" class="form-control" placeholder="Contact No" value="<?php
                        if (isset($_GET['edit'])) echo $getRow->getEmailContact();
                        elseif (isset($_POST['create'])) echo $_POST['contact'];
                        ?>" required>
                        <span style="color: darkred"><?php if (isset($_POST['create'])&&empty($_POST['contact'])) echo '*Contact is required';?></span>
                    </div>
                </div>

                <!--            Contact Email-->
                <div class="form-group">
                    <label for="contactEmail" class="control-label col-md-3">Contact Email :</label>
                    <div class=" col-md-7">
                        <input type="email" name="contactEmail" id="contactEmail" class="form-control" placeholder="Contact Email" value="<?php
                        if (isset($_GET['edit'])) echo $getRow->getEmailContactEmail();
                        elseif (isset($_POST['create'])) echo $_POST['contactEmail'];
                        ?>" required>
                        <span class="span-danger"><?php if (isset($_POST['create'])&&empty($_POST['contactEmail'])) echo '*Contact Email is required';?></span>
                    </div>
                </div>

                <!--            Address-->
                <div class="form-group">
                    <label for="address" class="control-label col-md-3">Address :</label>
                    <div class=" col-md-7">
                        <textarea name="address" id="address" rows="7" class="form-control" required><?php
                            if (isset($_GET['edit'])) echo $getRow->getEmailAddress();
                            elseif (isset($_POST['create'])&&!empty($_POST['address'])) echo $_POST['address'];
                            ?></textarea>
                        <span class="span-danger"><?php if (isset($_POST['create'])&&empty($_POST['address'])) echo '*Address is required';?></span>
                    </div>
                </div>

                <!--            Created At-->
                <div class="form-group">
                    <label for="createdAt" class="control-label col-md-3">Created At :</label>
                    <div class=" col-md-7">
                        <input type="date" name="createdAt" id="createdAt" class="form-control" placeholder="Created At" value="<?php
                        if (isset($_GET['edit'])) echo $getRow->getEmailCreatedAt();
                        elseif (isset($_POST['create'])) echo $_POST['createdAt'];
                        ?>" required>
                        <span class="span-danger"><?php if (isset($_POST['create'])&&empty($_POST['createdAt'])) echo '*Created At is required';?></span>
                    </div>
                </div>

                <!--            Expire At-->
                <div class="form-group">
                    <label for="expireAt" class="control-label col-md-3">Expire At :</label>
                    <div class=" col-md-7">
                        <input type="date" name="expireAt" id="expireAt" class="form-control" placeholder="Expire At" value="<?php
                        if (isset($_GET['edit'])) echo $getRow->getEmailExpireAt();
                        elseif (isset($_POST['create'])) echo $_POST['expireAt'];
                        ?>" required>
                        <span class="span-danger"><?php if (isset($_POST['create'])&&empty($_POST['expireAt'])) echo '*Expire At is required';?></span>
                    </div>
                </div>
                <br>

                <!--Button-->
                <div class="form-group">
                    <?php
                    if (!isset($_GET['edit'])){
                        ?>
                        <input type="submit" class="btn btn-primary col-md-2 col-md-offset-5" name="create" value="Create">
                        <?php
                    }else{
                        ?>
                        <input type="submit" class="btn btn-primary col-md-2 col-md-offset-5" name="update" value="Update">
                        <?php
                    }
                    ?>
                </div>

            </form>
        </div>
    </div>
</div>
</div>
<div class="col-md-12">
    <hr>
</div>
<div class="col-md-12">
<div class="panel panel-table">
    <table class="table table-bordered table-responsive">
        <!--Header Row-->
        <tr>
            <th>Email</th>
            <th>Name</th>
            <th>Contact</th>
            <th>Contact Email</th>
            <th>Address</th>
            <th>Created At</th>
            <th>Expire At</th>
            <th><img src="./resources/img/edit.ico" height="40" width="40" alt="Edit" class="table-img"></th>
            <th><img src="./resources/img/delete.png" height="40" width="40" alt="Delete" class="table-img"></th>
        </tr>

        <!--Table Cells-->
        <?php
        $Result=$_EmailBao->getAllEmail();
        if($Result->getIsSuccess()){
            $EmailList=$Result->getResultObject();

            foreach ($EmailList as $email) {

                $expire = $email->getEmailExpireAt();
                $currentDate = new DateTime('now');
                $expireDate = new DateTime($expire);
                $validity = date_diff($currentDate, $expireDate);
                $isValid = true;
                $safe = true;
                $warning = false;
                $danger = false;
                if ($validity->format("%R%a") > 90) {
                    $isValid = true;
                    $safe = true;
                    $warning = false;
                    $danger = false;
                } elseif ($validity->format("%R%a") > 30) {
                    $isValid = true;
                    $safe = false;
                    $warning = true;
                    $danger = false;
                } elseif ($validity->format("%R%a") > -1) {
                    $isValid = true;
                    $safe = false;
                    $warning = false;
                    $danger = true;
                } else {
                    $isValid = false;
                    $safe = false;
                    $warning = false;
                    $danger = true;
                }
                ?>
                <tr class="table-cell <?php
                if ($isValid) {
                    if ($safe) {
                        echo ' alert-success';
                    } elseif ($warning) {
                        echo ' alert-warning';
                    } else {
                        echo ' alert-danger';
                    }
                } else {
                    echo ' alert-danger';
                }
                ?>">
                    <td style="color: darkblue"><?php echo $email->getEmailEmail(); ?></td>
                    <td><?php echo $email->getEmailFirstName() . ' ' . $email->getEmailLastName(); ?></td>
                    <td><?php echo $email->getEmailContact(); ?></td>
                    <td><?php echo $email->getEmailContactEmail(); ?></td>
                    <td><?php echo $email->getEmailAddress(); ?></td>
                    <td><?php echo $email->getEmailCreatedAt(); ?></td>
                    <td><?php echo $email->getEmailExpireAt(); ?></td>

                    <td>
                        
                            <a href="?edit=<?php echo $email->getEmailId(); ?>"
                               onclick="return confirm('sure to edit !');">Extend</a>
                            
                        
                        
                    </td>

                    <td>
                        <a href="?del=<?php echo $email->getEmailId(); ?>"
                           class="span-danger"
                           onclick="return confirm('sure to delete !');">delete</a>
                    </td>
                </tr>
                <?php
            }
        }
        ?>
    </table>
</div>
</div>
