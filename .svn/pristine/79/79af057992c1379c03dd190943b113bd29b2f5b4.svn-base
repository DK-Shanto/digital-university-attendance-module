<?php

include_once 'blade/view.upload_cv.blade.inc';
include_once COMMON.'class.common.inc';


if($flag==true && !isset($_POST['edit'])){
?>
	<div class="panel panel-default">
    
    <div class="panel-heading " style="text-align: center;" ><h2>Student CV Information</h2></div>
    		<div class="container-fluid" style="background-color:#A2DA93;">
    				
    				<div class="row">
    					<div class="col-sm-1"></div>
    					<div class="col-sm-3">
    						<img style="margin-top: 30px;" src="<?php echo './resources/img/scholarship/images/'.$globalStudent->getPicSource() ; ?>" alt="Icon" height="220" width="200" >
    					</div>
    					<div class="col-sm-6">
    						<ul class="list-group">
						      <li class="list-group-item list-group-item-success" style="font-size: 21px; margin-top: 82px; ">Student ID : <?php echo $userPositions->getUniversityID(); ?></li>
						      <li class="list-group-item list-group-item-success" style="font-size: 21px;">Student Name : <?php echo $userPositions->getFirstName()." ".$userPositions->getMiddleName()." ".$userPositions->getLastName(); ?></li>
						  	</ul>
    					</div>
    					
    				</div>

					  
					  <br>
		
					  <div class="row">

					      <div class="row" id="attribute">
					      	<div class="col-sm-4">
						      	<ul class="list-group" style="margin-left: 15px;">		
								  <li class="list-group-item active">Discipline : <?php echo $userPositions->getDiscipline()->getName(); ?></li>
								  <li class="list-group-item active">Email : <?php echo $userPositions->getEmail(); ?></li>
								  <li class="list-group-item active">Father's Name : <?php echo $userDetails->getFatherName(); ?></li>
								  <li class="list-group-item active">Mother's Name : <?php echo $userDetails->getMotherName(); ?></li>
								  <li class="list-group-item active">Present Address : <?php echo $userDetails->getCurrentAddress(); ?></li>
								  <li class="list-group-item active">Permanent Address : <?php echo $userDetails->getPermanentAddress(); ?></li>
								  <li class="list-group-item active">Contact No : <?php echo $userDetails->getMobilePhone(); ?></li>  
								</ul>
						    </div>
						    <div class="col-sm-4">
						    <ul class="list-group">
						      
							  <li class="list-group-item">Age : <?php echo $globalStudent->getAge(); ?></li>
							  <li class="list-group-item">Father's Proffession : <?php echo $globalStudent->getFatherProf(); ?></li>
							  <li class="list-group-item">Mother's Proffession : <?php echo $globalStudent->getMotherProf(); ?></li>
							  <li class="list-group-item">Yearly Income : <?php echo $globalStudent->getIncome(); ?></li>
							  <li class="list-group-item">Siblings : <?php echo $globalStudent->getSibling(); ?></li>
							  <li class="list-group-item">Year-Term : <?php echo $globalStudent->getCurrentTerm(); ?></li>

							</ul>
							</div>
							<div class="col-sm-4">
							<ul class="list-group" style=" margin-right: 15px;">	
							  <li class="list-group-item">Reason For Apply : <?php echo $globalStudent->getReason(); ?></li>
							  <li class="list-group-item">Cocurricular Activity : <?php echo $globalStudent->getCocurricular(); ?></li>
							  <li class="list-group-item">Quota : <?php echo $globalStudent->getQuota();  ?></li>
							  <li class="list-group-item">Average CGPA : <?php echo $globalStudent->getCgpa(); ?></li>
							  <li class="list-group-item"><p>Parent's Contact No : <?php echo $userDetails->getMobilePhone(); ?></p></li>
							  <li class="list-group-item"><p>Document : <a href="<?php echo './resources/img/scholarship/documents/'.$globalStudent->getDocument() ; ?>">Additional File</a></p></li>
							</ul>
							  	
							
						</div>
							    
					    
					   
					  </div> 
					  <div class="row" id="form">
					  	<form method="post" class="form-horizontal">

								<div class="form-group">
									<button type="submit" value="edit" name="edit" style="margin-left: 100px;">Edit</button>
								</div>
								
						</form>
					  </div>
			  </div>  

					  
		</div>
	</div>
    
<?php
}
else{
?>


<div class="panel panel-default">
    
    <div class="panel-heading " style="text-align: center;" ><h2>Fill up the Following Information</h2></div>
    
    
    <div class="panel-body">
		<div id="form">
			<div class="container-fluid">
			<form method="post" class="form-horizontal" enctype="multipart/form-data" >

				<div class="form-group" style="padding-top: 25px;">
	              	<label class="control-label col-sm-5" for="txtAge">Age**:</label>
	              	<div class="col-sm-6">
				  		<input type="text" name="txtAge" class="form-control" placeholder="Enter your age" 
				  		value="<?php if($flag==true) echo $globalStudent->getAge(); ?>" required/>
				  	</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="txtFatherProf">Father's Occupation**:</label>
	              	<div class="col-sm-6">
	              		<input type="text" name="txtFatherProf" class="form-control" placeholder="Use a short and Unique Profession"
	              		value="<?php if($flag==true) echo $globalStudent->getFatherProf(); ?>" required/>
				  	</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="txtMotherProf">Mother's Occupation**:</label>
	              	<div class="col-sm-6">
	              		<input type="text" name="txtMotherProf" class="form-control" placeholder="Use a short and Unique Profession" value="<?php if($flag==true) echo $globalStudent->getMotherProf(); ?>" required/>
				  	</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="txtIncome">Yearly Income**:</label>
	              	<div class="col-sm-6">  		
						<input type="text" name="txtIncome" class="form-control" placeholder="Such as..120000 in Taka" value="<?php if($flag==true) echo $globalStudent->getIncome(); ?>" required/>
					</div>
				</div>

				

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="selectSibling">Siblings**:</label>
	              	<div class="col-sm-6">		
							   						    
							<select name="selectSibling" class="form-control" id="select-from-roles" required>
								<option selected disabled>Select Number of Siblings</option>
								<option value="1">1</option>
								<option value="2">2</option>
								<option value="3">3</option>
								<option value="4">4</option>
								<option value="5">5</option>
								<option value="6">6</option>
								<option value="7">7</option>
								<option value="8">8</option>
								<option value="9">9</option>
								<option value="10">10</option>

							<?php
							if($flag == true){
							?>
								<option selected value= "<?php echo $globalStudent->getSibling(); ?>">
									<?php echo $globalStudent->getSibling(); ?></option>
							<?php
							}
							?>
							</select>
					</div>
				</div>


				<div class="form-group">
	              	<label class="control-label col-sm-5" for="txtReason">Reason For Apply:</label>
	              	<div class="col-sm-6">
	              		<textarea type="text" id="txtReason" name="txtReason" class="form-control" placeholder="Give a short description about your reason" rows="5" text-align="left"><?php if($flag==true) echo $globalStudent->getReason(); ?>
	              		</textarea>
				  	</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="selectCocurricular">Cocurricular Activity:</label>
	              	<div class="col-sm-6">	

								<?php
								$Result = $_CocurricularBAO->getAllCocurriculars();
								if ($Result->getIsSuccess()){
									$CocurricularList = $Result->getResultObject();

								}
								?>
								<select name="selectCocurricular" class="form-control">
									<option selected disabled>Select Cocurricular Activity if you have any</option>
									<?php
									for ($i = 0; $i<sizeof($CocurricularList); $i++){
										$Cocurricular = $CocurricularList[$i];
										
										if ($flag==false){

										?>
											<option value="<?php echo $Cocurricular->getShortName();?>" > <?php echo $Cocurricular->getCocurricularName(); ?> 
											</option>
											<?php
										}
										else{

											if ($globalStudent->getCocurricular() == $Cocurricular->getShortName()){
												?>
												<option selected value = "<?php echo $Cocurricular->getShortName();?>" > 
													<?php echo $Cocurricular->getCocurricularName();?> 
												</option>
												<?php
											}
											else {

												?>
												<option value="<?php echo $Cocurricular->getShortName();?>" > <?php echo $Cocurricular->getCocurricularName(); ?> 
												</option>
												<?php
											}	
										}

									}
									?>	
								</select>
					</div>
				</div>	

				
				<div class="form-group">
	              	<label class="control-label col-sm-5" for="selectQuota">Quota:</label>
	              	<div class="col-sm-6">	

								<?php
								$Result = $_QuotaBAO->getAllQuotas();
								if ($Result->getIsSuccess()){
									$QuotaList = $Result->getResultObject();

								}
								?>
								<select name="selectQuota" class="form-control">
									<option selected disabled>Select quota if you have any</option>
									<?php
									for ($i = 0; $i<sizeof($QuotaList); $i++){
										$Quota = $QuotaList[$i];
										
										if ($flag==false){

										?>
											<option value="<?php echo $Quota->getShortName();?>" > <?php echo $Quota->getQuotaName(); ?> 
											</option>
											<?php
										}

										else{

											if ($globalStudent->getQuota() == $Quota->getShortName()){
												?>
												<option selected value = "<?php echo $Quota->getShortName();?>" > 
													<?php echo $Quota->getQuotaName();?> 
												</option>
												<?php
											}
											else {

												?>
												<option value="<?php echo $Quota->getShortName();?>" > <?php echo $Quota->getQuotaName(); ?> 
												</option>
												<?php
											}	
										}
										
									}
									?>	
								</select>
					</div>
				</div>	
		
				

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="selectTerm">Year-Term**:</label>
	              	<div class="col-sm-6">	
						<select name="selectTerm" class="form-control" id="select-from-roles" required>
								<option selected disabled>Select Current Year & Term</option>
								<option value="1-1">1-1</option>
								<option value="1-2">1-2</option>
								<option value="2-1">2-1</option>
								<option value="2-2">2-2</option>
								<option value="3-1">3-1</option>
								<option value="3-2">3-2</option>
								<option value="4-1">4-1</option>
								<option value="4-2">4-2</option>
							<?php
							if($flag == true){
							?>
								<option selected value= "<?php echo $globalStudent->getCurrentTerm(); ?>">
									<?php echo $globalStudent->getCurrentTerm(); ?></option>
							<?php
							}
							?>	
							</select>	
					</div>
				</div>

				

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="txtCgpa">Average CGPA**:</label>
	              	<div class="col-sm-6">
				  		<input type="text" name="txtCgpa" class="form-control" placeholder="Emter CGPA avergae till now" value="<?php if($flag==true) echo $globalStudent->getCgpa(); ?>" required/>
				  	</div>
				</div>

				

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="uploadfile">Picture**:</label>
	              	<div class="col-sm-6">
				  		<input type="file" name="uploadImage" class="form-control" value="submit"/>
				  	</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-5"></label>
	              	<div class="col-sm-6">
				  		<p style="text-align: left;">* You have to add a picture with 200 X 300 pixels or a passport size photo.</p>
				  	</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-5" for="uploadFile">Document:</label>
	              	<div class="col-sm-6">
				  		<input type="file" name="uploadFile" class="form-control" value="submit" />
				  	</div>
				</div>
				<div class="form-group">
	              	<label class="control-label col-sm-5"></label>
	              	<div class="col-sm-6">
				  		<p style="text-align: left; font-style: bold;">* If you want to add some extra document for attachment then add it as Microsoft Text Document</p>
				  	</div>
				</div>

				
		        <div class="form-group">        
	              	<div class="col-sm-offset-2 col-sm-10">
						<?php
							if($flag==true)
							{
						?>
								<button type="submit" value="update" name="update">update</button>
								<?php
							}
							else
							{
								?>
								<button type="submit" value="save" name="save">submit</button>
								<?php
							}
								?>
				    </div>
	            </div> 
			</form>
		</div>

	</div>
	</div>
</div>	
<?php
}
?>

