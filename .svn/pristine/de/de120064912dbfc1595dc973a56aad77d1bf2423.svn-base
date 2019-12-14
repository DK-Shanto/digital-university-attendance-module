<?php

include_once 'blade/view.book_search.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">

    <div class="panel-heading">Book Information</div>

    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal" enctype="multipart/form-data">

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtBookTitle">Title:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtBookTitle" class="form-control" placeholder="Enter the Book Name"/>
			  	</div>
			</div>
      <div class="form-group">
              	<label class="control-label col-sm-4" for="txtBookEdition">Edition:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtBookEdition" class="form-control" placeholder="Enter the Book Edition"/>
			  	</div>
			</div>
      <div class="form-group">
              	<label class="control-label col-sm-4" for="txtBookWritter">Writter:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtBookWritter" class="form-control" placeholder="Enter the Writter Name"/>
			  	</div>
			</div>
      <div class="form-group">
              	<label class="control-label col-sm-4" for="assignedRoles">Sorted By:</label>
              	<div class="col-sm-6">

						    <?php
						    // this block of code prints the list box of roles with current assigned  roles

						    $var = '<select name="assignedCategory" class="form-control" id="assignedCategory" required>';

						   	$var = $var. '<option value=1';

						    $var = $var.'>Date</option>';

                $var = $var. '<option value=2';

						    $var = $var.'>Price</option>';

                $var = $var. '<option value=3';

						    $var = $var.'>Date and Price</option>';

                $var = $var. '<option value=4';

						    $var = $var.'>Price and Date</option>';

								$var = $var.'</select>';

							echo $var;
							?>
				</div>
			</div>
      <div class="form-group">
          	<div class="col-sm-offset-2 col-sm-10">
			             <button type="submit" value="request" name="request">Search</button>
	          </div>
      </div>

		</form>

	</div>
	<div id="toastME">Some Text Message..</div>
	</div>

</div>
<?php

if(isset($_POST['request']))
{
    $Book = new Book();
    $Result = $_BookListBAO->getAllBook();
    //if DAO access is successful to load all the Books then show them one by one
    if($Result->getIsSuccess()){
      $name = $_POST['txtBookTitle'];
      $name = preg_replace('/\s/', '', $name);
      $edition = $_POST['txtBookEdition'];
      $edition = preg_replace('/\s/', '', $edition);
      $writter = $_POST['txtBookWritter'];
      $writter = preg_replace('/\s/', '', $writter);
      $name_len = strlen($name);
      $edition_len = strlen($edition);
      $writter_len = strlen($writter);
      $filter = $_POST['assignedCategory'];

      if($filter == 1)
      {
        $str = "ORDER BY date DESC";
      }
      else if($filter == 2)
      {
        $str = "ORDER BY ammount";
      }
      else if($filter == 3)
      {
        $str = "ORDER BY date DESC, ammount";
      }
      else if($filter == 4)
      {
        $str = "ORDER BY ammount, date DESC";
      }
      if($name_len != 0 && $edition_len != 0 && $writter_len != 0)
      {
        $qry = "SELECT * FROM bsms_book WHERE LOWER(bsms_book.name) LIKE LOWER('%".$name."%') AND LOWER(bsms_book.edition) LIKE LOWER('%".$edition."%') AND LOWER(bsms_book.writter) LIKE LOWER('%".$writter."%') ".$str;
      }
      else if($name_len == 0 && $edition_len != 0 && $writter_len != 0)
      {
        $qry = "SELECT * FROM bsms_book WHERE LOWER(bsms_book.edition) LIKE LOWER('%".$edition."%') AND LOWER(bsms_book.writter) LIKE LOWER('%".$writter."%') ".$str;
      }
      else if($name_len != 0 && $edition_len == 0 && $writter_len != 0)
      {
        $qry = "SELECT * FROM bsms_book WHERE LOWER(bsms_book.name) LIKE LOWER('%".$name."%') AND LOWER(bsms_book.writter) LIKE LOWER('%".$writter."%') ".$str;
      }
      else if($name_len != 0 && $edition_len != 0 && $writter_len == 0)
      {
        $qry = "SELECT * FROM bsms_book WHERE LOWER(bsms_book.name) LIKE LOWER('%".$name."%') AND LOWER(bsms_book.edition) LIKE LOWER('%".$edition."%') ".$str;
      }
      else if($name_len != 0 && $edition_len == 0 && $writter_len == 0)
      {
        $qry = "SELECT * FROM bsms_book WHERE LOWER(bsms_book.name) LIKE LOWER('%".$name."%') ".$str;
      }
      else if($name_len == 0 && $edition_len != 0 && $writter_len == 0)
      {
        $qry = "SELECT * FROM bsms_book WHERE LOWER(bsms_book.edition) LIKE LOWER('%".$edition."%') ".$str;
      }
      else if($name_len == 0 && $edition_len == 0 && $writter_len != 0)
      {
        $qry = "SELECT * FROM bsms_book WHERE LOWER(bsms_book.writter) LIKE LOWER('%".$writter."%') ".$str;
      }
      else
      {
        header("Location:".PageUtil::$BOOK_SEARCH);
      }
      $BookList = $Result->getResultObject();
      ?>
      <?php
      $con = mysqli_connect("localhost","root","");
      mysqli_select_db($con,"cseku");

      $res = mysqli_query($con,$qry);
      if (!$res) {
        printf("Error: %s\n", mysqli_error($con));
        exit();
      }
      $i = 0;
      for(;$row = mysqli_fetch_array($res); $i++) {
        $Book = $BookList[$i];
        ?>
        <div style="float:left; width:33.33%; height:350px;padding-left:50px">
          <div style="height: 320px;width: 400px;box-sizing: border-box ;border: 1px solid blue; color:black; border-radius:25px; ">


            <h4 style="color:blue;padding-left:35%"><p>#Post Number:  <?php echo $i+1 ?></p></h4>

            <p style="padding-left:30px" ><span>Posted By: </span><?php echo $row['user_name']; ?></p>

            <p style="padding-left:30px"><span>Book Title: </span><?php echo $row['name']; ?></p>

            <p style="padding-left:30px"><span>Book Edition: </span> <?php echo $row['edition']; ?></p>

            <p style="padding-left:30px"><span>Writter Name: </span><?php echo $row['writter']; ?></p>

            <p style="padding-left:30px"><span>Description: </span><?php echo $row['description']; ?></p>

            <p style="padding-left:30px"><span>Ammount: </span><?php echo $row['ammount']." Taka"; ?></p>

            <p style="padding-left:30px"><span>Contact Number: </span><?php echo $row['contact_number']?></p>

            <p style="padding-left:30px"><span>Post Date: </span><?php echo $row['date']?></p>

            <br /><br />
            </div>
          </div>
      <?php
      }
      if($i == 0)
      {
        echo "No Result Has Been Found!!";
      }
    }
    else{
      echo $Result->getResultObject(); //giving failure message
    }
}
?>
