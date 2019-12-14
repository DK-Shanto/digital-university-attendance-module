<?php
include_once 'blade/view.book_list.blade.inc';
include_once COMMON.'class.common.inc';
include_once UTILITY.'class.util.inc';
?>

<div class="panel panel-default">

    <div class="panel-heading">Book Information</div>

    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal" enctype="multipart/form-data">

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtBookTitle">Title**:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtBookTitle" class="form-control" placeholder="Enter the Book Name" value="<?php if(isset($_GET['edit'])) echo $globalBook->getTitle(); ?>" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtBookEdition">Edition**:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtBookEdition" class="form-control" placeholder="Edition Number  of The Book" value="<?php if(isset($_GET['edit'])) echo $globalBook->getEdition(); ?>" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtWritter">Writter**:</label>
              	<div class="col-sm-6">
					<input type="text" name="txtWritter" class="form-control" placeholder="Enter Writter's Name" value="<?php if(isset($_GET['edit'])) echo $globalBook->getWritter(); ?>" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtDescription">Description**:</label>
              	<div class="col-sm-6">
					<input type="text" name="txtDescription" class="form-control" placeholder="Condition of Your Book" value="<?php if(isset($_GET['edit'])) echo $globalBook->getDescription(); ?>" required/>
				</div>
			</div>

      <div class="form-group">
                <label class="control-label col-sm-4" for="txtAmmount">Ammount**:</label>
                <div class="col-sm-6">
            <input type="number" name="txtAmmount" class="form-control" placeholder="Selling Price of The Book in Taka" value="<?php if(isset($_GET['edit'])) echo $globalBook->getAmmount(); ?>" maxlength="6"/>
          </div>
      </div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtContactNumber">Contact Number**:</label>
              	<div class="col-sm-6">
			  		<input type="text" name="txtContactNumber" class="form-control" placeholder="0 1 * * * * * * * * *" maxlength="11" value="<?php if(isset($_GET['edit'])) echo $globalBook->getContactNumber(); ?>" required/>
			  	</div>
			</div>
      <!-- Upload Image -->
      <!-- <div class="form-group">
              	<label class="control-label col-sm-4" for="txtImage[]">Upload Image</label>
              	<div class="col-sm-6">
			  		<input type="file" name="txtImage[]" multiple="multiple" class="form-control"/>
			  	</div>
			</div> -->
<!-- 			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtfile">Upload a PDF file or image of Attested Details**:</label>
              	<div class="col-sm-6">
					<input type="file" name="txtfile"/>
				</div>
			</div> -->

	        <div class="form-group">
              	<div class="col-sm-offset-2 col-sm-10">
					             <button type="submit" value="update" name="update">Update This Book</button>
			          </div>
          </div>

		</form>

	</div>
	<div id="toastME">Some Text Message..</div>
	</div>

<div class="panel panel-default">
    <div class="panel-heading">
    </div>
    <div class="panel-body">
    	<?php
			$Result = $_BookListBAO->getAllBook();
			//if DAO access is successful to load all the Books then show them one by one
			if($Result->getIsSuccess()){
				$BookList = $Result->getResultObject();
				?>
				<?php

        $con = mysqli_connect("localhost","root","");
        mysqli_select_db($con,"cseku");

        $qry = "SELECT * FROM bsms_book";
        $res = mysqli_query($con,$qry);
				for($i = 0; $i < sizeof($BookList); $i++) {
          ///$row = mysql_fetch_array($res);

					$Book = $BookList[$i];

					?>
					<div style="float:left; width:33.33%; height:350px;padding-left:50px">
            <div style="height: 320px;width: 400px;box-sizing: border-box ;border: 1px solid blue; color:black; border-radius:25px; ">


              <h4 style="color:blue;padding-left:35%"><p>#Post Number:  <?php echo $i+1 ?></p></h4>

              <p style="padding-left:30px" ><span>Posted By: </span><?php echo $Book->getUserName(); ?></p>

					    <p style="padding-left:30px"><span>Book Title: </span><?php echo $Book->getTitle(); ?></p>

					    <p style="padding-left:30px"><span>Book Edition: </span> <?php echo $Book->getEdition(); ?></p>

					    <p style="padding-left:30px"><span>Writter Name: </span><?php echo $Book->getWritter(); ?></p>

              <p style="padding-left:30px"><span>Description: </span><?php echo $Book->getDescription(); ?></p>

					    <p style="padding-left:30px"><span>Ammount: </span><?php echo $Book->getAmmount()." Taka"; ?></p>

					    <p style="padding-left:30px"><span>Contact Number: </span><?php echo $Book->getContactNumber()?></p>

					    <p style="padding-left:30px"><span>Post Date: </span><?php echo $Book->getDate()?></p>

              <?php
              $userID="";
              $userID = $_SESSION["globalUser"];
              $id = $userID->getID();
              $id_db = $Book->getUserID();
              if($id_db == $id)
              {
                ?>
                <a href="?edit=<?php echo $Book->getBookID(); ?>" onclick="return confirm('Sure to edit!'); " style="padding-left:30px" >Edit</a>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <a href="?delete=<?php echo $Book->getBookID(); ?>" onclick="return confirm('Sure to delete !'); " style="padding-left:30px" >Delete</a>
                <?php
              }
              ?>
              <br /><br />
              </div>
            </div>
				<?php
				}
			}
			else{
				echo $Result->getResultObject(); //giving failure message
			}
		?>
    </div>
</div>
