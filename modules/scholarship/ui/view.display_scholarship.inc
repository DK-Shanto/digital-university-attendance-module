<?php

include_once 'blade/view.display_scholarship.blade.inc';
include_once COMMON.'class.common.inc';

?>

<style type="text/css">
	#attribute{
		margin-left: 4px;
	}

	#btnApply{
		padding: 7px 29px; margin-left: 28px; margin-top: 14px;
	}
</style>



<?php

if(isset($_GET['apply'])){
?>

<div class="panel panel-default">
    
    <div class="panel-heading " style="text-align: center;" ><h2>Student Application Form</h2></div>
    
    
    <div class="panel-body">
    	
    	<div class="row">
    		<div class="col-sm-1"></div>
    		<div class="col-sm-10">

    			<br><br>
    			<div class="container-fluid" style="background-color:#E1E2E6;">
    				<div class="row" style="text-align: center;"><h3>Scholarship Information</h3></div>
    				<div class="row">
    					<div class="col-sm-10">
    						<h3><?php echo $globalScholarship->getTitle(); ?></h3>
    					</div>
    					
    				</div>

					  
					  <br>
					  <div class="row" id="attribute">
					      <p><?php echo $globalScholarship->getSubtitle(); ?></p>
					  </div> 
					  <div class="row">

					      <div class="row" id="attribute">
							    <div class="col-sm-4">
							      <p>Category : <?php echo $globalScholarship->getCategory(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Organization : <?php echo $globalScholarship->getOrganization(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Contact No : <?php echo $globalScholarship->getContactNumber(); ?></p>
							    </div>
							   
							  </div> 
					  </div>  

					  <div class="row">
					      <div class="row" id="attribute">
							     <div class="col-sm-4">
							      <p>Age limit : <?php echo $globalScholarship->getAgeLimit(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Posted Date : <?php echo $globalScholarship->getPublishDate(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Email : <?php echo $globalScholarship->getEmail(); ?></p>
							    </div>
							    
							  </div> 
					  </div>  

					  <div class="row">
					      <div class="row" id="attribute">
					      		
							    <div class="col-sm-4">
							      <p>Eligible Gender : <?php echo $globalScholarship->getGender(); ?></p>
							    </div>
							     <div class="col-sm-4">
							      <p>Amount : <?php echo $globalScholarship->getScholarshipAmount(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Last Date of Application : <?php echo $Scholarship->getLastDateOfApplication(); ?></p>
							    </div>
					    </div>
					  </div> 


				</div>
    		
    			<br>
    			<?php
				if($flag == true){
				?>
    			<div class="container-fluid" style="background-color:#A2DA93;">
    				<div class="row" style="text-align: center;"><h3>Applicant Information</h3></div>
    				<div class="row">
    					<div class="col-sm-10">
    						<h4>Student ID : <?php echo $userPositions->getUniversityID(); ?></h4>
    						<h4>Student Name : <?php echo $userPositions->getFirstName()." ".$userPositions->getMiddleName()." ".$userPositions->getLastName(); ?></h4>
    					</div>
    					
    					
    				</div>

					  
					  <br>
		
					  <div class="row">

					      <div class="row" id="attribute">
							    <div class="col-sm-4">
							      <p>Discipline : <?php echo $userPositions->getDiscipline()->getName(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Email : <?php echo $userPositions->getEmail(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Father's Name : <?php echo $userDetails->getFatherName(); ?></p>
							    </div>
							   
							  </div> 
					  </div>  

					  <div class="row">
					      <div class="row" id="attribute">
							     <div class="col-sm-4">
							      <p>Mother's Name : <?php echo $userDetails->getMotherName(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Permanent Address : <?php echo $userDetails->getPermanentAddress(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Present Address : <?php echo $userDetails->getCurrentAddress(); ?></p>
							    </div>
							    
							  </div> 
					  </div>  

					  <div class="row">
					      <div class="row" id="attribute">
					      		
							    <div class="col-sm-4">
							      <p>Parent's Contact No : <?php echo $userDetails->getMobilePhone(); ?></p>
							    </div>
							     <div class="col-sm-4">
							      <p>Age : <?php echo $globalStudent->getAge(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Father's Proffession : <?php echo $globalStudent->getFatherProf(); ?></p>
							    </div>
					    </div>
					  </div> 

					  <div class="row">
					      <div class="row" id="attribute">
					      		
							    <div class="col-sm-4">
							      <p>Yearly Income : <?php echo $globalStudent->getIncome(); ?></p>
							    </div>
							     <div class="col-sm-4">
							      <p>Siblings : <?php $globalStudent->getSibling(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Mother's Proffession : <?php echo $globalStudent->getMotherProf(); ?></p>
							    </div>
					    </div>
					  </div> 

					  <div class="row">
					      <div class="row" id="attribute">
					      		
							    <div class="col-sm-4">
							      <p>Reason For Apply : <?php echo $globalStudent->getReason(); ?></p>
							    </div>
							     <div class="col-sm-4">
							      <p>Cocurricular Activity : <?php echo $globalStudent->getCocurricular(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Quota : <?php echo $globalStudent->getQuota();  ?></p>
							    </div>
					    </div>
					  </div> 

					  <div class="row">
					      <div class="row" id="attribute">
					      		
							    <div class="col-sm-4">
							      <p>Year-Term : <?php echo $globalStudent->getCurrentTerm(); ?></p>
							    </div>
							     <div class="col-sm-4">
							      <p>Average CGPA : <?php $globalStudent->getCgpa(); ?></p>
							    </div>
							    <div class="col-sm-4">
							      <p>Document : <?php echo $globalStudent->getMotherProf(); ?></p>
							    </div>
					    </div>
					  </div> 
				</div>
				<div id="form">
				<form method="post" class="form-horizontal">
						
				        <div class="form-group">        
			              <div class="col-sm-offset-2 col-sm-10">
								<?php
								if(isset($_GET['edit']))
								{
									?>
									<button type="submit" name="update">update</button>
									<?php
								}
								else
								{
									?>
									<button type="submit" name="save">SUBMIT</button>
									<?php
								}
								?>
							</div>
						</div>	

				</form>
				</div>
				
				<?php
				}
				else{
				?>
				<div class="container-fluid" style="background-color:#D9534F;">
    				<div class="row" style="text-align: center;"><h3>First You have to upload a CV</h3></div>
    			</div>	


				<?php	
				}
				?>
			
			
			</div>		
    		<div class="col-sm-1"></div>
    	</div>	
    	  
	</div>

</div>

<?php
}

if(!isset($_GET['apply'])){
?>

<div class="panel panel-default">
    
    <div class="panel-heading " style="text-align: center;" ><h2>All Scholarships Information</h2></div>
    <br>
    
    <div class="panel-body">
    	<div class="row">
    		<div class="col-sm-1"></div>
    		<div class="col-sm-10">
    		<?php


			$Result = $_ScholarshipBAO->getAllScholarships();

			//if DAO access is successful to load all the users then show them one by one
			if($Result->getIsSuccess()){

				$ScholarshipList = $Result->getResultObject();
			
			

    		for($i=0; $i<sizeof($ScholarshipList); $i++){ 

    			$Scholarship = $ScholarshipList[$i];

    			$id = $Scholarship->getID();
    			$temp=false;

    			if($temp1 == true){
	    			for($j=0; $j<sizeof($StudentHasScholarshipList); $j++){
	    				//$StudentHasScholarship = new StudentHasScholarship();
	    				$StudentHasScholarship = $StudentHasScholarshipList[$j];
	    				$_ScholarshipID = $StudentHasScholarship->getScholarshipID();
	    				if($id == $_ScholarshipID){
	    					$temp=true;
	    				}
	    			}
    			}
    		?>
    		
    			<br><br>
    			<div class="container-fluid" style="background-color:#E1E2E6;">
    				<div class="row">
    					<div class="col-sm-10">
    						<h3><?php echo $Scholarship->getTitle(); ?></h3>
    					</div>
    					<div class="col-sm-2">
    						<?php
    						if($temp==false){
    						?>
    						<a href="?apply=<?php echo $Scholarship->getID(); ?>" onclick="return confirm('sure to apply !'); " >
    							<button class="btn btn-success btn-lg" id="btnApply" type="submit">Apply
    							</button>
    						</a>
    						<?php
    						}
    						else{
    						?>
    						<a href="?apply=<?php echo $Scholarship->getID(); ?>" onclick="return confirm('sure to apply !'); " >
    							<button class="btn btn-danger btn-md disabled" id="btnApply" type="submit">Applied
    							</button>
    						</a>
    						<?php
    						}
    						?>

    						
    					</div>
    				</div>

					  
					  <br>
					  <div class="row" id="attribute">
					      <p><?php echo $Scholarship->getSubtitle(); ?></p>
					  </div> 
					  <div class="row">

					      <div class="row" id="attribute">
							    <div class="col-sm-3">
							      <p>Category : <?php echo $Scholarship->getCategory(); ?></p>
							    </div>
							    <div class="col-sm-3">
							      <p>Organization : <?php echo $Scholarship->getOrganization(); ?></p>
							    </div>
							    <div class="col-sm-3">
							      <p>Contact No : <?php echo $Scholarship->getContactNumber(); ?></p>
							    </div>
							   
							  </div> 
					  </div>  

					  <div class="row">
					      <div class="row" id="attribute">
							     <div class="col-sm-3">
							      <p>Age limit : <?php echo $Scholarship->getAgeLimit(); ?></p>
							    </div>
							    <div class="col-sm-3">
							      <p>Posted Date : <?php echo $Scholarship->getPublishDate(); ?></p>
							    </div>
							    <div class="col-sm-3">
							      <p>Email : <?php echo $Scholarship->getEmail(); ?></p>
							    </div>
							    
							  </div> 
					  </div>  

					  <div class="row">
					      <div class="row" id="attribute">
					      		
							    <div class="col-sm-3">
							      <p>Eligible Gender : <?php echo $Scholarship->getGender(); ?></p>
							    </div>
							     <div class="col-sm-3">
							      <p>Amount : <?php echo $Scholarship->getScholarshipAmount(); ?></p>
							    </div>
							    <div class="col-sm-3">
							      <p>Last Date of Application : <?php echo $Scholarship->getLastDateOfApplication(); ?></p>
							    </div>
					    </div>
					  </div> 


				</div>
			
			<?php } 
			}
			else{

				echo $Result->getResultObject(); //giving failure message
			}

			?>
			</div>		
    		<div class="col-sm-1"></div>
    	</div>	
    	  
	</div>
</div>

<?php
}
?>








