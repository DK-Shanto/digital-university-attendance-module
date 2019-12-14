<?php

include_once 'blade/view.book_post.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">

    <div class="panel-heading">New Book Information</div>

    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal" enctype="multipart/form-data">

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtBookTitle">Title**:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtBookTitle" class="form-control" placeholder="Enter the Book Name" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtBookEdition">Edition**:</label>
              	<div class="col-sm-6">
              		<input type="text" name="txtBookEdition" class="form-control" placeholder="Edition Number  of The Book" required/>
			  	</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtWritter">Writter**:</label>
              	<div class="col-sm-6">
					<input type="text" name="txtWritter" class="form-control" placeholder="Enter Writter's Name" required/>
				</div>
			</div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtDescription">Description**:</label>
              	<div class="col-sm-6">
					<input type="text" name="txtDescription" class="form-control" placeholder="Condition of Your Book" required/>
				</div>
			</div>

      <div class="form-group">
                <label class="control-label col-sm-4" for="txtAmmount">Ammount**:</label>
                <div class="col-sm-6">
            <input type="number" name="txtAmmount" class="form-control" placeholder="Selling Price of The Book in Taka" maxlength="6"/>
          </div>
      </div>

			<div class="form-group">
              	<label class="control-label col-sm-4" for="txtContactNumber">Contact Number**:</label>
              	<div class="col-sm-6">
			  		<input type="text" name="txtContactNumber" class="form-control" placeholder="0 1 * * * * * * * * *" maxlength="11" required/>
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
					             <button type="submit" value="request" name="request">Post This Book</button>
			          </div>
          </div>

		</form>

	</div>
	<div id="toastME">Some Text Message..</div>
	</div>

</div>
